import sys

print("Enter input: ", end="")
sys.stdout.flush()

raw_input = sys.stdin.readline()

if len(raw_input) > 0 and raw_input[len(raw_input) - 1] == '\n':
    user_input = raw_input
else:
    user_input = raw_input

print("You entered:", user_input)
