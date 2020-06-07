import subprocess


class Solver(object):
    def __init__(self, solver="kube_solver.exe", args = [], skip_header=True, set_end_string=True):
        """
        Create a new solver instance.

        Keyword arguments:

        solver -- path to the solver executable to use (default solver.exe)
        """
        self.process = subprocess.Popen(
            [solver] + args, bufsize=0, stdin=subprocess.PIPE, stdout=subprocess.PIPE, universal_newlines=True)

    def __enter__(self):
        return self
    
    def __exit__(self, type, value, traceback):
        self.exit()

    def exit(self):
        self.process.kill()
        self.process.wait(1)
        self.process.__exit__(None, None, None)
    
    def end_of_input(self):
        self.process.stdin.close()

    def write_line(self, line):
        self.write_lines([line])

    def write_lines(self, lines):
        self.process.stdin.write("\n".join(lines))
        self.process.stdin.write("\n")
    
    def read_line(self):
        line = self.process.stdout.readline()
        if not line:
            raise Exception("Unexpected end of output.")
        return line

    def read_all_lines(self):
        result = []
        while True:
            line = self.process.stdout.readline()
            if not line:
                return result
            result.append(line)