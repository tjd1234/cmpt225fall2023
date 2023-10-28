# count.py

#
# Python program that counts words in a file.
#

import sys

if __name__ == "__main__":

    if len(sys.argv) != 2:
        print("Usage: python3 count.py <filename>")
        sys.exit(1)

    # get all the words from the input file
    filename = sys.argv[1]
    words = open(filename).read().split()

    d = {}  # make empty dictionary
    for w in words:
        if w in d:
            d[w] += 1
        else:
            d[w] = 1
    
    print(f'{len(d)} unique words')
    print(f'd["good"] = {d["good"]}')
