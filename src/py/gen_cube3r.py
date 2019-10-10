def applyCycle(target, cycle):
    c0,c1,c2,c3 = cycle
    t3 = target[c3]
    target[c3] = target[c2]
    target[c2] = target[c1]
    target[c1] = target[c0]
    target[c0] = t3

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

def writeRotationFuctions(f, name, edgeCycles, cornerCycles):
    edges = list(range(24))
    corners = list(range(24))

    for i in range(3):
        for ec in edgeCycles:
            applyCycle(edges, ec)

        for cc in cornerCycles:
            applyCycle(corners, cc)
        lines = write_single_rotation_function("{}_{}".format(name, i+1), edges, corners)
        for l in lines:
            f.write(l)
            f.write("\n")
            #print(l)
        f.write("\n")
        #print()

faces = {
     "R" : { "e": [[12,13,14,15], [1,19,9,5]], "c" :[[12,13,15,14], [5,1,18,9], [3,16,11,7]]},
     "U" : { "e": [[0,1,2,3], [20, 16, 12, 4]], "c" :[[0,1,3,2], [17,13,5,21], [16, 12, 4,20]]},
     "F" : { "e": [[4,5,6,7], [2, 15, 8, 21]], "c" :[[4,5,7,6], [2, 12, 9, 23], [3, 14, 8, 21]]},
     "L" : { "e": [[20,21,22,23], [3, 7, 11,17]], "c" :[[20, 21, 23, 22 ], [0, 4, 8, 19], [2, 6, 10, 17]]},
     "D" : { "e": [[8,9,10,11], [6,14,18,22]], "c" :[[8,9,11,10], [6, 14, 18, 22], [7, 15, 19, 23]]},
     "B" : { "e": [[16,17,18,19], [0,23,10,13]], "c" :[[16, 17, 19, 18], [1, 20, 10, 15], [0, 22, 11, 13]]},

    "r" : { "e": [[0, 18, 8, 4], [2, 16, 10, 6]], "c" :[]},
    "u" : { "e": [[1, 20, 11, 14], [3, 22, 9, 12]], "c" :[]},
}

turn_faces = ["R", "U", "F", "L", "D", "B", "r", "u"]

rotations = (

)

with open(r'src/c/cube3r.c', "w") as f:

    all_rotations = []
    all_rotations_s = []
    
    f.write("const int ALL_ROTATION_LEN = {};\n\n".format(3 * len(turn_faces)) )

    for name in turn_faces:
        d = faces[name]
        edgeCycles = d["e"]
        cornerCycles = d["c"]
        writeRotationFuctions(f, name, edgeCycles, cornerCycles)
        all_rotations.append(name + "_1")
        all_rotations.append(name + "_2")
        all_rotations.append(name + "_3")
        all_rotations_s.append(name)
        all_rotations_s.append(name+"2")
        all_rotations_s.append(name+"'")

    f.write("t_rotation all_rotations[] = {\n")
    f.write(",\n".join(all_rotations))
    f.write("\n};\n")

    f.write("char* all_rotations_s[] = {\n\"")
    f.write("\",\n\"".join(all_rotations_s))
    f.write("\"\n};\n")