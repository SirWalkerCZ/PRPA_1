import subprocess
import unittest

class TestCProgram(unittest.TestCase):
    def test_valid_input(self):
        for last_number in range(3, 69):
            input_data = f"69 69 {last_number}\n"
            print(input_data)
            expected_output = "Error: Neplatna velikost plotu!\n"
            self.assertEqual(run_c_program(input_data), expected_output)
            
def run_c_program(input_data):
    command = ['./main']
    process = subprocess.Popen(command, stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
    stdout, stderr = process.communicate(input=input_data)
    return stderr

if __name__ == '__main__':
    unittest.main()