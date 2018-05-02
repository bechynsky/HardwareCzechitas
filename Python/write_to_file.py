

# create text file

# second parameter is type of access to file
# r - read, file must exist
# w - write, if file exists it is overwriten, if not it creates new
# a - append, if file exists it writes to end of file, if not it creates new
with open("data.csv", "w") as f:
    # decimal separator is . it can be issue in some regional settings
    # \n creates new line
    f.write("number;decimal number\n")

    for i in range(0,20):
        f.write("{0};{1}\n".format(i,i/10))

    f.close()

