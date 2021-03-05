import re
import itertools

# Given strings
txt1 = "Dog12, CAT3, LiOn7, DolphiN11, fish6"
txt2 = "PIG17, bear29, BiRd8, SNAKE39, donkey14"


# Python code to convert string to list
def convert(strings):
    li = list(strings.split(", "))
    return li


# Lists
li1 = convert(txt1)
li2 = convert(txt2)
li1 = [x.lower() for x in li1]
li2 = [x.lower() for x in li2]


# Splitting txt
def split(li):
    items = [];
    for animal in li:
        match = re.match(r"([a-z]+)([0-9]+)", animal, re.I)
        if match:
            items += match.groups()
    return items


li1 = split(li1)
li2 = split(li2)

# Dictionaries
dict1 = dict(itertools.zip_longest(*[iter(li1)] * 2, fillvalue=""))
dict2 = dict(itertools.zip_longest(*[iter(li2)] * 2, fillvalue=""))
dic = {
    1: "animal code",
    2: "animal name"}


# Searching code in dictionary
def search_code(strings, dictionary):
    for name, code in dictionary.items():  # for name, age in dictionary.iteritems():  (for Python 2.x)
        if code == strings:
            print(dic[choice] + ": The code entered " + strings + " name of animal found " + name)
            return True


# Searching name in dictionary
def search_name(strings, dictionary):
    for name, code in dictionary.items():  # for name, age in dictionary.iteritems():  (for Python 2.x)
        if name == strings:
            print(dic[choice] + ": The name entered " + strings + " code of animal found " + code)
            return True


# Starting to run program
print("Welcome to the Database; Please select a search option:"
      "\n1. By " + dic[1] +
      "\n2. By " + dic[2])
try:
    choice = int(input("\nPlease enter 1 or 2\n"))
    string = input("Please insert " + dic[choice] + " data for search\n").lower()

    # print according to user choice
    if choice == 1:
        if not search_code(string, dict1) and not search_code(string, dict2):
            raise Exception("name of animal not found")

    if choice == 2:
        if not search_name(string, dict1) and not search_name(string, dict2):
            raise Exception("code of animal not found")

except KeyError as err:
    template = "An exception of type {0} occurred. Arguments:\n{1!r}"
    message = template.format(type(err).__name__, err.args)
    print(message)

except Exception as err:
    template = "An exception of type {0} occurred. Arguments:\n{1!r}"
    message = template.format(type(err).__name__, err.args)
    print(message)
