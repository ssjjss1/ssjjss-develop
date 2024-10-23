dic = {
    "January": 1,
    "February": 2,
    "March": 3,
    "April": 4,
    "May": 5,
    "June": 6,
    "July": 7,
    "August": 8,
    "September": 9,
    "October": 10,
    "November": 11,
    "December": 12
}
while True:
    s = input().strip()
    if s == "0 #":
        break
    day, month = s.split()
    day = int(day)
    if month == "February" and day == 29:
        print("Unlucky")
    elif dic[month] < 8 or (dic[month] == 8 and day < 4):
        print("Yes")
    elif dic[month] == 8 and day == 4:
        print("Happy birthday")
    else:
        print("No")