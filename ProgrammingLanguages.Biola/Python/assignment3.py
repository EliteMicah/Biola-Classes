print("This program will calculate the average grade for all the scores entered.")
print("Enter -1 when finished.")
userInput = int(input("Enter Score: "))
scores = []
while userInput != -1:
    scores.append(userInput)
    userInput = int(input("Enter Score: "))

total = 0
length = len(scores)
for x in scores:
    total = total + x
average = total / length

print("The average grade is: ", average)
