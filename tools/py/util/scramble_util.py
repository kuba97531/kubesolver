def reverse_move(move):
    if not move: return ""
    if move.endswith("2"):
        return move
    if move.endswith("'"):
        return move[:-1]
    return move + "'"

def reverse_sequence(sequence):
    result = []
    for s in reversed(sequence.split()):
        result.append(reverse_move(s))
    return " ".join(result)

# fix sequence so that it can be understood by kubesolver
def fix_sequence(sequence):
    return sequence.replace("(", " ").replace(")", " ").replace("2'", "2")