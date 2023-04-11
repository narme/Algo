def plus(num1, num2) :
    return num1 + num2

def minus(num1, num2) :
    return num1 - num2

def multiple(num1, num2) :
    return num1 * num2

def devide(num1, num2) :
    return num1 / num2

choice = 0

while(choice != -1) :

    print("1. ADD 2. MINUS 3. MULTIPLE 4. DEVIDE")
    print("Enter the menu (Enter -1 to exit): ")
    choice = int(input())
        
    if(choice == -1) :
        print("201713829")
        break
        
    
    num1 = int(input("input :"))
    num2 = int(input("input :"))

    if(choice == 1) :
        print("result : ", plus(num1, num2))
    elif(choice == 2) :
        print("result : ", minus(num1, num2))
    elif(choice == 3) :
        print("result : ", multiple(num1, num2))
    elif(choice == 4) :
        print("result : ", devide(num1, num2))

