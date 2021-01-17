fileName=input("Podaj nazwe pliku\n")
wordToFind=input("Podaj slowo\n")
with open(fileName) as file:
    for num, line in enumerate(file, 1):
        if wordToFind in line:
            print("Wyraz znaleziono na lini: " + str(num))
    file.close()
