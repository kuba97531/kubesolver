KubeSolver 1.0
==============
Copyrights & Author: Jakub Straszewski, 2020

General
-------

The program is able to solve 3x3 Rubik's cube.

The most prominent usecase it the ability to easly generate algorithms for particular cases. It's very easy to generate things like:
 - Generation of algorithms for any last-layer subset (PLL, ZBLL), OLL, OLLCP, last slot + EO.
 - finding sequences for crosses, x-crosses, eo-crosses.

It supports limited generators, and it can include all standard moves (RUF..), wide moves(lru...), slice moves(MES) and rotations(xyz).

It implements a relatively robust brute-force algorithm.

The simple two-phase solver is there for completness but it's not particularly good or fast.

Architecture
------------
KubeSolver is a command-line application. It reads commands from standard input and writes output to standard output.

Example usecases:
----------------

1) Basic alg generation
in.txt:
F R U R' U' F'
kubesolver.exe < in.txt > out.txt
out.txt:
INFO:KubeSolver 1.0 (C) Jakub Straszewski 2020
INFO:Searching 1 move solutions...
INFO:Searching 2 move solutions...
INFO:Searching 3 move solutions...
INFO:Searching 4 move solutions...
INFO:Searching 5 move solutions...
INFO:Searching 6 move solutions...
F U R U' R' F'                           
INFO:Searching 7 move solutions...       
INFO:Searching 8 move solutions...       
U' R U B U' B' R' U                      
(...)

kubesolver.exe --silent < in.txt > out.txt
out.txt:
F U R U' R' F'                           
U' R U B U' B' R' U                      
(...)

2) This example will reconstruct the given U-perm with MU-gen
in.txt:
set_gen MU
R2 U R U R' U' R' U' R' U R'
reconstruct

3) This example shows how to generate OLL algorithms for sune-case.
in.txt:
init_empty_cube
add_f2l
add_edges_orientation
add_corners_orientation
set_gen RULD
R U R' U R U2 R'
solve

4) This example shows how to solve a yellow cross:
init_empty_cube
add_edge DR
add_edge DL
add_edge DB
add_edge DF
F2 L2 F' D2 L2 F' R2 B2 D2 L2 U2 L' D L B2 R' D' U' R F2
solve
./kubesolver.exe --silent -n 1 < in.txt
F2 D' L2 B F'

5) this example shows how to solve a yellow-xcross with a BL slot.
init_empty_cube
add_edge DR
add_edge DL
add_edge DB
add_edge DF
add_edge BL
add_corner BLD
F2 L2 F' D2 L2 F' R2 B2 D2 L2 U2 L' D L B2 R' D' U' R F2
solve

5) this example shows how to solve a cube with 2-phase algorithm.
F2 L2 F' D2 L2 F' R2 B2 D2 L2 U2 L' D L B2 R' D' U' R F2
solve_two_phase
L F2 D2 L2 R' B2 U' F2 L B' U' R2 D' B2 D R2 D' L2 F2 U2 B2 U' F2 D

Program command line arguments:
-------------------------------
--silent                                  - don't print Info: statements
--max-number-of-sequences N, -n N         - stop search after finding N sequences (default unlimited)
--max-depth-of-search N, -d N             - only search sequences of length at most N (doesn't apply to two phase solver)


List of commands:
-----------------
To be done. At the moment examples secion covert most of the api.

Commands for setting up a cube:
------------------
set_gen XXX - specified the list of moves allowed in the algorithm. Examples: RU, rRU (wide moves), MES (slice moves), L2U2R2D2BF (only 180 turns). Defaults to RLUDFB
init_full_cube (default)
init_empty_cube
Note: the command below make only sense after calling init_empty_cube
add_edge xx
add_corner yy
add_edges_orientation - all edges that has not been added explicitely by add_edge will be required to have good orientation (according to the LRUD-gen)
add_corners_orientation - same as edges
add_corners_permutation - all corners that has not been added explicitely by add_corner will be required to be in a correct spot ignoring their orientation.
add_f2l - adds all edges and corners for bottom two layers.

init_to_current_state - make current state a new starting state. It makes sense if you want to force e.g. a particular OLL (to force a known ZBLL)

Commands to solve a cube:
-------------------------
solve - generate algorithms solving given cube state
reconstruct - generate algorithms solving the reverse cube state
solve_two_phase - will solve 3x3 cube using two-phase algorithm ignoring init moves (so it will solve the full cube for specified sequence)

Licence
-------

Free to use for any use. No guarantees or liability of any kind accepted.