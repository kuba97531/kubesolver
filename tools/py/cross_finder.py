from util import scramble_util
from util.solver import Solver
import sys

cross_orientations = [
    "", # white on top
    "x", # green on top
    "x2", # yellow on top
    "x'", # blue on top
    "z", # orange on top
    "z'", # red on top
]
 
scramble_moves = " ".join(sys.argv[1:])

for orientation in cross_orientations:
    with Solver("kube_solver.exe", ["--silent"]) as solver:
        solver.write_line("set da 0") # find only optimal crosses
        solver.write_line("init_empty_cube") 
        solver.write_line("add_edge DF")
        solver.write_line("add_edge DB")
        solver.write_line("add_edge DR")
        solver.write_line("add_edge DL")
        solver.write_line(scramble_util.reverse_move(orientation))
        solver.write_line(scramble_moves)
        solver.write_line(orientation)
        solver.write_line("solve")
        solver.end_of_input()
        print("optimal crosses for orientation " + orientation)
        for line in solver.read_all_lines():
            print(orientation + " " + line.strip())



        
        
        
        
        
        
        
        