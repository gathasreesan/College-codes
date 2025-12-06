f1 = open("file1.txt", "r")  # replace with your actual file name or path
x = f1.read()
# convert to lowercase
x = x.lower()
# remove punctuation (keep only letters, numbers, and spaces)
x = ''.join(i for i in x if i.isalnum() or i.isspace())
# split into words
l = x.split()
# create dictionary to count words
wc = dict()
for i in l:
    if i in wc:
        wc[i] += 1
    else:
        wc[i] = 1
# find most frequent word
most_frequent_word = max(wc, key=wc.get)
most_frequent_count = wc[most_frequent_word]
print("The most occurring word is", most_frequent_word, "with", most_frequent_count, "occurrences.")
f1.close()
