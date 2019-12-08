def apply4Cycle(target, cycle):
    c0,c1,c2,c3 = cycle
    t3 = target[c3]
    target[c3] = target[c2]
    target[c2] = target[c1]
    target[c1] = target[c0]
    target[c0] = t3

def apply6permutation(target, permutation):
    for i in range(6):
        target[i] = permutation[target[i]]


def write_single_rotation_function(name, edges, corners):
    result = []
    result.append("cube {}(cube *other) {{ ".format(name))
    result.append("    cube result = *other;")
    for i in range(24):
        if edges[i] != i:
            result.append("    result.edges[{}] = other->edges[{}];".format(i, edges[i]))
    for i in range(24):
        if corners[i] != i:
            result.append("    result.corners[{}] = other->corners[{}];".format(i,corners[i]))
    result.append("    return result;")
    result.append("}")
    return result;   

def writeRotationFuctions(fc, fh, name, edgeCycles, cornerCycles):
    edges = list(range(24))
    corners = list(range(24))

    for i in range(3):
        for ec in edgeCycles:
            apply4Cycle(edges, ec)

        for cc in cornerCycles:
            apply4Cycle(corners, cc)
        lines = write_single_rotation_function("{}_{}".format(name, i+1), edges, corners)
        for l in lines:
            fc.write(l)
            fc.write("\n")
            #print(l)
        fc.write("\n")

        fh.write(get_function_header("{}_{}".format(name, i+1)))
        fh.write("\n")
        #print()

def get_function_header(name):
    return "cube {}(cube *other);".format(name)

def write_single_symmetry_function(name, edges, corners, colors):
    result = []
    result.append("cube {}(cube *other) {{".format(name))
    result.append("    cube result;")
    result.append("    int color_swap[7] = {{ {}, 6 }};".format(", ".join(map(str,colors))))
    for i in range(24):
        result.append("    result.edges[{}] = color_swap[other->edges[{}]];".format(i, edges[i]))
    for i in range(24):
        result.append("    result.corners[{}] = color_swap[other->corners[{}]];".format(i,corners[i]))
    result.append("    return result;")
    result.append("}")
    return result;   

faces = {
     "R" : { "e": [[12,13,14,15], [1,19,9,5]], "c" :[[12,13,15,14], [5,1,18,9], [3,16,11,7]]},
     "U" : { "e": [[0,1,2,3], [20, 16, 12, 4]], "c" :[[0,1,3,2], [17,13,5,21], [16, 12, 4,20]]},
     "F" : { "e": [[4,5,6,7], [2, 15, 8, 21]], "c" :[[4,5,7,6], [2, 12, 9, 23], [3, 14, 8, 21]]},
     "L" : { "e": [[20,21,22,23], [3, 7, 11,17]], "c" :[[20, 21, 23, 22 ], [0, 4, 8, 19], [2, 6, 10, 17]]},
     "D" : { "e": [[8,9,10,11], [6,14,18,22]], "c" :[[8,9,11,10], [6, 14, 18, 22], [7, 15, 19, 23]]},
     "B" : { "e": [[16,17,18,19], [0,23,10,13]], "c" :[[16, 17, 19, 18], [1, 20, 10, 15], [0, 22, 11, 13]]},

    "farR" : { "e": [[0, 18, 8, 4], [2, 16, 10, 6]], "c" :[]},
    "farU" : { "e": [[5, 21, 17, 13], [7, 23, 19, 15]], "c" :[]},
    "farF" : { "e": [[1, 14, 11, 20], [3, 12, 9, 22]], "c" :[]},
}

turn_faces = ["R", "U", "F", "L", "D", "B"]

x_centers = [4,0,1,3,2,5]
y_centers = [0,5,2,1,3,4]
z_centers = [3,1,5,2,4,0]


x_centers_reverse = [1,2,4,3,0,5]
y_centers_reverse = [0,3,2,4,5,1]
z_centers_reverse = [5,1,3,0,4,2]


basic_symmetries = {
    "x" : { "faces" : ["R", "L'", "farR"], "centers" : x_centers},
    "y" : { "faces" : ["U", "D'", "farU" ], "centers" : y_centers},
    "z" : { "faces" : ["F", "B'", "farF"], "centers" : z_centers},
    "M" : { "faces" : ["farR'"], "centers" : x_centers_reverse},
    "E" : { "faces" : ["farU'"], "centers" : y_centers_reverse},
    "S" : { "faces" : ["farF"], "centers" : z_centers},
    "r" : { "faces" : ["R", "farR"], "centers" : x_centers},
    "l" : { "faces" : ["L", "farR'"], "centers" : x_centers_reverse},
    "u" : { "faces" : ["U", "farU"], "centers" : y_centers},
    "d" : { "faces" : ["D", "farU'"], "centers" : y_centers_reverse},
    "f" : { "faces" : ["F", "farF"], "centers" : z_centers},
    "b" : { "faces" : ["B", "farF'"], "centers" : z_centers_reverse},
}

wide_moves_and_rotations = ["x", "y", "z", "M", "E", "S", "r", "l", "u", "d", "f", "b"]

families = [ "RLrlM", "FBfbS", "UDudE", "x", "y", "z" ]
family_dict = {}
for family in families:
    for ch in family:
        family_dict[ch] = family[0]

def expand(sequence):
    result = []
    for s in sequence:
        if s.endswith('2'):
            result.append(s[:-1])
            result.append(s[:-1])
        elif s.endswith('\''):
            result.append(s[:-1])
            result.append(s[:-1])
            result.append(s[:-1])
        else:
            result.append(s)
    return result

def write_symmetry_function(fc, fh, name, applied_symmetries):
    edges = list(range(24))
    corners = list(range(24))
    centers = list(range(6))
    
    for s in applied_symmetries:
        for facename in expand(s["faces"]):
            face = faces[facename]
            for ec in face["e"]:
                apply4Cycle(edges, ec)
            
            for cc in face["c"]:
                apply4Cycle(corners, cc)

        apply6permutation(centers, s["centers"])

    lines = write_single_symmetry_function(name, edges, corners, centers)
    for l in lines:
        fc.write(l)
        fc.write("\n")
        #print(l)
    header = get_function_header(name)
    fh.write(header)
    fh.write("\n")

    fc.write("\n")

if __name__ == "__main__":
    with open(r'src/c/cube3r.c', "w") as fc:
        with open(r'src/c/cube3r.h', "w") as fh:

            all_rotations = []
            all_rotations_s = []
            all_families = []

            fh.write("#include \"cube3.h\"\n")
            fh.write("#ifndef CUBE3_R\n")
            fh.write("#define CUBE3_R\n")

            fc.write("#include \"cube3r.h\"\n")

            def append_rotation_name(name):
                all_rotations.append(name + "_1")
                all_rotations.append(name + "_2")
                all_rotations.append(name + "_3")
                all_rotations_s.append(name)
                all_rotations_s.append(name+"2")
                all_rotations_s.append(name+"'")
                all_families.append(family_dict[name])
                all_families.append(family_dict[name])
                all_families.append(family_dict[name])

            for name in turn_faces:
                d = faces[name]
                edgeCycles = d["e"]
                cornerCycles = d["c"]
                writeRotationFuctions(fc, fh, name, edgeCycles, cornerCycles)
                append_rotation_name(name)

            def bs(x):
                return basic_symmetries[x]

            for name in wide_moves_and_rotations:
                for i in (1,2,3):
                    write_symmetry_function(fc, fh, "%s_%d" % (name, i), map(bs, [name] * i) ) 
                append_rotation_name(name)

            fh.write("#define ALL_ROTATION_LEN {}\n\n".format(len(all_rotations_s)) )
            fh.write("extern t_rotation all_rotations[];\n")
            fh.write("extern char* all_rotations_s[];\n")
            fh.write("extern const char rotation_families[];\n")

            fc.write("t_rotation all_rotations[] = {\n")
            fc.write(",\n".join(all_rotations))
            fc.write("\n};\n")

            fc.write("char* all_rotations_s[] = {\n\"")
            fc.write("\",\n\"".join(all_rotations_s))
            fc.write("\"\n};\n")

            fc.write("const char rotation_families[] = \"")
            fc.write("".join(all_families))
            fc.write("\";\n")

            fh.write("\n#endif\n")