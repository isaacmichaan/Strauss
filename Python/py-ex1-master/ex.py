# ex1
def ex1():
    myList = [1, 3, 4, 3, 1, 2, 6, 3, 5, 6, 7]
    myList = list(dict.fromkeys(myList))
    print(myList)
    orderList = sorted(myList)
    print(orderList)

# ex2
def ex2():
    def reverse_text(text):
        return text[::-1]

    def input_type(text):
        if text.isalpha():
            return "isAlpha"
        if text.isnumeric():
            return "isNumeric"
        return "isAlNum"

    def palindrome(text):
        w = ""
        for i in text:
            w = i + w
        if text == w:
            return "Yes"
        return "No"

    def upper_lower(text):
        if not text.isnumeric():
            op = int(input("1 - upper or 2 - lower"))
            if op == 1:
                return text.upper()
            else: return text.lower()
        raise Exception("No letters")

    def replace_char(text):
        text = list(text)
        index = int(input("index"))
        letter = input("letter")
        text[index] = letter
        return "".join(text)

    myDict = {
      1: "Reverse text",
      2: "Input type",
      3: "Palindrome",
      4: "Upper or Lower",
      5: "Replace char"
    }

    dictOption = {
        "Reverse text": reverse_text,
        "Input type": input_type,
        "Palindrome": palindrome,
        "Upper or Lower": upper_lower,
        "Replace char": replace_char
    }

    try:
        text = input("input some text")
        print("select option", myDict)
        option = int(input())
        answer = dictOption[myDict[option]](text)
        print(answer)
    except Exception as e:
        print(e)


i = int(input("ex1 - 1 or ex2 - 2"))
ex = [ex1, ex2]
ex[i - 1]()