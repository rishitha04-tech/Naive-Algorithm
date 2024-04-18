def search(pat, txt):
    M = len(pat)
    N = len(txt)

    # A loop to slide pat[] one by one */
    for i in range(N - M + 1):
        j = 0

        # For current index i, check
        # for pattern match */
        while(j < M):
            if (txt[i + j] != pat[j]):
                break
            j += 1

        if (j == M):
            print("Pattern found at index ", i)


if __name__ == '__main__':
    txt_file = input("Enter the path of the text file: ")
    pat_file = input("Enter the path of the pattern file: ")

    try:
        with open(txt_file, 'r') as f:
            txt = f.read().strip()
    except FileNotFoundError:
        print("Text file not found.")
        exit(1)

    try:
        with open(pat_file, 'r') as f:
            pat = f.read().strip()
    except FileNotFoundError:
        print("Pattern file not found.")
        exit(1)

    # Function call
    search(pat, txt)
