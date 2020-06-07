import unittest
from solver import Solver

from os import listdir
from os.path import isfile, join

class ShowRangeTest(unittest.TestCase):
    def setUp(self):
        pass
    def tearDown(self):
        pass
        
    def test_explore(self):
        test_scenarios = "tests/scenarios"
        test_input_files = [f for f in listdir(test_scenarios) if isfile(join(test_scenarios, f)) and f.endswith(".in")]
        for f in test_input_files:
            with self.subTest(input_file=(f)):
                with Solver("kube_solver.exe") as solver:
                    with open(join(test_scenarios, f), "r") as input_file:
                        for line in input_file:
                            solver.write_line(line)
                    solver.end_of_input()
                    result = [line.strip() for line in solver.read_all_lines() if line.strip() and not line.startswith("INFO:")]

                    with open(join(test_scenarios, f[:-3]+".out"), "r") as f:
                        expected = [line.strip() for line in f if line.strip() and not line.startswith("INFO:")]

                    def take_one(items):
                        return items[0], items[1:]

                    while result and expected:
                        result_line, result = take_one(result)
                        expexted_line, expected = take_one(expected)
                        if result_line != expexted_line:
                            raise AssertionError("\nExpected Line: "+expexted_line+"\n" +
                                                    "Encountered  : "+result_line)
                    
                    # with open('filename') as f:
                    #     expected_line = [line.rstrip() for line in f]       
        


