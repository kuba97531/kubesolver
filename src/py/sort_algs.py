import sys

def qtm(seq):
    result = 0
    for move in seq:
        if move.startswith("("):
            result += 0 # this line does nothing, but I added it for clarity that we weight AUF as 0
        elif "2" in move:
            result += 2
        else:
            result += 1
    return result

def htm(seq):
    result = 0
    for move in seq:
        if move.startswith("("):
            result += 0 # this line does nothing, but I added it for clarity that we weight AUF as 0
        else:
            result += 1
    return result

eval_dict = {
    "R": 1,
    "R'": 1,
    "R2": 1.5,

    "L": 1.1,
    "L'": 1.1,
    "L2": 1.6,

    "U": 1,
    "U'": 1,
    "U2": 1.3,

    "D": 1.1,
    "D'": 1.1,
    "D2": 1.9,

    "F": 1.6,
    "F'": 1.6,
    "F2": 1.6,

    "B": 2,
    "B'": 2.2,
    "B2": 3.5,
}

def eval_sequence(seq):
    result = 0
    for move in seq:
        if move.startswith("("):
            result += 0 # this line does nothing, but I added it for clarity that we weight AUF as 0
        else:
            result += eval_dict[move]
    return result


if __name__ == '__main__' :
    if len(sys.argv) == 2:
        file_to_process = sys.argv[1]
    else:
        print("please provide a file as an argument")
        exit(1)
    
    all_sequences = []
    with open(file_to_process, "r", encoding="UTF-8") as f:
        for line in f:
            line = line.strip()
            if line and not line.startswith("INFO"):
                seq = line.split()
                #remove U.
                if seq[0].startswith("U"):
                    seq[0] = "(%s)" % seq[0]
                if seq[-1].startswith("U"):
                    seq[-1] = "(%s)" % seq[-1]
                    
                all_sequences.append([seq, eval_sequence(seq)])
    for (alg, score) in sorted(all_sequences, key = lambda x:x[1]):
        print("score=%.2f qtm=%d htm=%d\n%s" % (score, qtm(alg), htm(alg), " ".join(alg)))


