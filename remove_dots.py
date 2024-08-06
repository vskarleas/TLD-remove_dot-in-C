import re

def remove_dot_and_write(input_filename, output_filename):
    with open(input_filename, 'r') as f:
        lines = f.readlines()
    with open(output_filename, 'w') as out_file:
        for line in lines:
            line = re.sub(r'\.', '', line)
            out_file.write(f"{line.strip()}, ")

if __name__ == '__main__':
    input_filename = 'cloudflare_tlds.txt'
    output_filename = 'cloudflare_tlds_no_dot.txt'
    remove_dot_and_write(input_filename, output_filename)
