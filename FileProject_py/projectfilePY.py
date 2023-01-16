def writestudent():
    with open ("student2.txt","a")as file:
        c='y'
        while c=='y':
            print("Welcome In Our Libarary System !\n")
            name = input("Enter Name: ")
            id=input( "Enter ID: ")
            age=input( "Enter Age: ")
            level=input("Enter Your Level If You A Student: ")
            phone=input("Enter Your Phone Number: ");
            file.write(id+'\t'+name+'\t'+age+'\t'+level+'\t'+phone+'\n')
            c=input("Do you want to enter records again (y \ n) ?")


def readstudent():
    with open("student2.txt","r")as file:
        print('ID\tName\tAge\tLevel\tPhone\n')
        print("---------------------")
        for line in file:
            print(line, end='\n')#defult end='\n'


def searchstudent():
    id=input("Enter The Id Of The Student To Search For:")
    with open("student2.txt","r")as file:
        flag=False
        for line in file:
            filds=line.split('\t')#filds if array seprated by \t
            if filds[0]==id:
                flag=True
                print('ID\tName\tAge\tLevel\tPhone\n')
                print("---------------------")
                print(line)
            if not flag:
                print("Student Not Found")


def deletestudent():
    import os
    id = input("Enter The Id Of The Student To Delete :")
    file=open("student2.txt","r")
    tempfile=open("tempstudent2.txt","w")
    flag = False
    for line in file:
        filds = line.split('\t')  # filds if array seprated by \t
        if filds[0] == id:
            flag = True
        else:
            tempfile.write(line)
    file.close()
    tempfile.close()
    os.remove("student2.txt")
    os.rename("tempstudent2.txt","student2.txt")
    if not flag:
        print("Student Not Found")
    else:
        print("Student Deleted Successfully")


def updatestudent():
    import os
    id = input("Enter The Id Of The Student To Update:")
    file = open("student2.txt", "r")
    tempfile = open("tempstudent2.txt", "w")
    flag = False
    for line in file:
        filds = line.split('\t') 
        if filds[0] == id:
            flag = True
            age=input('Enter The New Age For '+filds[1])
            line=filds[0]+'\t'+filds[1]+'\t'+age+'\t'+filds[3]+'\t'+filds[4]+'\n'
        tempfile.write(line)
    file.close()
    tempfile.close()
    os.remove("student2.txt")
    os.rename("tempstudent2.txt", "student2.txt")
    if not flag:
        print("Student Not Found")
    else:
        print("Student Updated Successfully")


def writebook():
    with open('bookpy.txt','a') as file:
        c='y'
        while c=='y':
            name=input('Enter name for book: ')
            id=input('Enter id for book: ')
            subject=input('Enter subject for book: ')
            file.write(name+'\t'+id+'\t'+subject+'\n')
            c=input('Do you want to enter record again: (y/n)?')


def readbook():
    with open('bookpy.txt','r') as file:
        print('Name\tid\tsubject')    
        print('------------------------')
        for line in file:
            print(line,end='')  


def searchbook():
    name=input('Enter name to search for: ')
    with open('bookpy.txt','r') as file:
        ok=False
        for line in file:
            fields=line.split('\t')
            if fields[0]==name:
                ok=True
                print('Name\tid\tsubject')    
                print('------------------------')
                print(line)
    if not ok:
        print('Book not found')            


def deletebook():
    import os
    name=input('Enter book name to delete: ')
    file=open('bookpy.txt','r')
    tempfile=open('bookpy2.txt','w')
    ok=False
    for line in file:
        field=line.split('\t')
        if field[0]==name:
            ok=True
        else:
            tempfile.write(line)
    file.close()
    tempfile.close()    
    os.remove('bookpy.txt')
    os.rename('bookpy2.txt','bookpy.txt')
    if not ok:
        print('book not found in file')
    else:
        print('book deleted successfully')    


def updatebook():
    import os
    name=input('Enter book name to update: ')
    file=open('bookpy.txt','r')
    tempfile=open('bookpy2.txt','w')
    ok=False
    for line in file:
        field=line.split('\t')
        if field[0]==name:
            ok=True
            id=input('Enter new id for book '+field[0]+' ')
            line=field[0]+'\t'+id+'\t'+field[2]
        tempfile.write(line)
    file.close()
    tempfile.close()    
    os.remove('bookpy.txt')
    os.rename('bookpy2.txt','bookpy.txt')
    if ok==True:
        print('book successfully update')
    else:
        print('No books are matched')    

        
def home():
    c='y'
    while c=='y':
        print('0: to add new book.')
        print('1: to read all book.')
        print('2: to search for book.')
        print('3: to delete book.')
        print('4: to update book.')
        print('5: to add new student.')
        print('6: to read all student.')
        print('7: to search for student.')
        print('8: to delete student.')
        print('9: to update student.')
        c=input('Your choice: ')
        if c=='0':
            writebook()
        elif c=='1':
            readbook()
        elif c=='2':
            searchbook()
        elif c=='3':
            deletebook()
        elif c=='4':
            updatebook()    
        elif c=='5':
            writestudent()
        elif c=='6':
            readstudent()
        elif c=='7':
            searchstudent()
        elif c=='8':
            deletestudent()
        else:
            updatestudent()                
        c=input('perform anther aperation (y/n): ') 
home()        