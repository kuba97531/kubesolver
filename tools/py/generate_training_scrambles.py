from util.solver import Solver
from util.scramble_util import fix_sequence
import random

pll = [
    "R2 U (R U R' U') R' U' (R' U R') ",
    "(R U' R U) R U (R U' R' U') R2  ",
    "x (R' U R') D2 (R U' R') D2 R2 x'  ",
    "x R2' D2 (R U R') D2 (R U' R) x'  ",
    "(R U' R' U') (R U R D) (R' U' R D') (R' U2 R')  ",
    " (R' U2 R U2') R' F (R U R' U') R' F' R2 ",
    " R2 U (R' U R' U') (R U' R2) D U' (R' U R D')",
    " D (R' U' R U) D' (R2 U R' U) (R U' R U') R2'",
    "R2 U' (R U' R U) (R' U R2 D') (U R U' R') D ",
    "D' (R U R' U') D (R2 U' R U') (R' U R' U) R2 ",
    ]

oll = [
    "(R U R' U') (R U' R') (F' U' F) (R U R') ",
    "F U (R U2 R' U') (R U2 R' U') F' ",
    "r U' r2' U r2 U r2' U' r ",
    "r' U r2 U' r2' U' r2 U r' ",
    "r' (R2 U R' U R U2 R') U M' ",
    "M' (R' U' R U' R' U2 R) U' M",
    "(r' U' R U') (R' U R U') R' U2 r ",
    "(r U R' U) (R U' R' U) R U2' r' "
    ]

last_slot = [
    "R U R'",
    "R U' R'",
    "R U' R' U R U' R'",
    "R U R' U' R U R'",
    "R U2 R' U' R U R'",
    "R U R' U2 R U' R'",
]

auf = [" ", " U ", " U2 ",  " U' "]

setup_groups = [
    auf,
    last_slot,
    auf,
    oll,
    auf,
    pll,
    auf
]

while True:
    setup = " ".join([fix_sequence(random.choice(g)) for g in setup_groups])
    with Solver("kube_solver.exe") as s:
        s.write_line("set n 1")
        s.write_line("set_gen RUFB")
        s.write_line(setup)
        print(setup)
        s.write_line("solve")
        s.end_of_input()
        with open("OLL_drill_2.txt", "a") as myfile:
            for line in s.read_all_lines():
                line = line.strip()
                if line and not line.startswith("INFO"):
                        myfile.write(line)
                        myfile.write(" ")
                        print(line)
            myfile.write("\n")
        print()