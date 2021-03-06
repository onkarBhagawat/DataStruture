using namespace std;
#include <iostream>
typedef struct Demo
{
    int Data;
    struct Demo *Next;
    struct Demo *Pre;
} NODE, *PNODE;

class SinglyL
{
private:
    PNODE Head;
    int Size;

public:
    SinglyL();
    void Display();
    int Count();
    void InsertFirst(int);
    void InsertLast(int);
    void DeleteFirst();
    void DeleteLast();
    void InsertAtPosition(int, int);
    void DeleteAtPosition(int);
};
SinglyL::SinglyL()
{
    Head = NULL;
    Size = 0;
}
inline void SinglyL::Display()
{
    PNODE Temp = Head;

    while (Temp != NULL)
    {
        cout << Temp->Data << "->";
        Temp = Temp->Next;
    }
    cout << "\n";
}

inline int SinglyL::Count()
{
    return Size;
}
void SinglyL::InsertFirst(int iNo)
{
    PNODE Newn = new NODE;
    Newn->Next = NULL;
    Newn->Data = iNo;
    if (Head == NULL)
    {
        Head = Newn;
    }
    else
    {
        Newn->Next = Head;
        Head = Newn;
    }
    Size++;
}
void SinglyL::InsertLast(int iNo)
{
    PNODE Newn = new NODE;
    Newn->Next = NULL;
    Newn->Data = iNo;
    PNODE Temp = Head;
    if (Head == NULL)
    {
        Head = Newn;
    }
    else
    {
        while (Temp->Next != NULL)
        {
            Temp = Temp->Next;
        }
        Temp->Next = Newn;
    }
    Size++;
}
void SinglyL::DeleteFirst()
{
    PNODE Temp = Head;
    if (Head == NULL)
    {
        return;
    }
    if (Head->Next == NULL)
    {
        delete (Head);
        Head = NULL;
    }
    else
    {
        Head = Head->Next;
        delete (Temp);
    }
    Size--;
}
void SinglyL::DeleteLast()
{
    PNODE Temp = Head;
    if (Head == NULL)
    {
        return;
    }
    else
    {
        while (Temp->Next->Next != NULL)
        {
            Temp = Temp->Next;
        }
        delete (Temp->Next);
        Temp->Next = NULL;
    }
    Size--;
}
void SinglyL::InsertAtPosition(int iNo, int Pos)
{
    Size = Count();
    if ((Pos < 0) || (Pos > Size + 1))
    {
        return;
    }
    if (Pos == 1)
    {
        InsertFirst(iNo);
    }
    else if (Pos == Size + 1)
    {
        InsertLast(iNo);
    }
    else
    {
        PNODE Newn = new NODE;
        Newn->Data = iNo;
        Newn->Next = NULL;
        PNODE Temp = Head;
        for (int i = 1; i < Pos - 1; i++)
        {
            Temp = Temp->Next;
        }

        Newn->Next = Temp->Next;
        Temp->Next = Newn;
    }
    Size++;
}
void SinglyL::DeleteAtPosition(int Pos)
{
    Size = Count();
    if ((Pos < 0) || (Pos > Size + 1))
    {
        return;
    }
    if (Pos == 1)
    {
        DeleteFirst();
    }
    else if (Pos == Size)
    {
        DeleteLast();
    }
    else
    {
        PNODE Newn = new NODE;
        Newn->Next = NULL;
        PNODE Temp = Head;
        for (int i = 1; i < Pos - 1; i++)
        {
            Temp = Temp->Next;
        }
        PNODE Temp1 = Temp->Next;
        Temp->Next = Temp->Next->Next;
        delete (Temp1);
    }
    Size--;
};

//----------------------------Singly Circlular--------------

class SinglyC
{
private:
    PNODE Head;
    PNODE Tail;
    int Size;

public:
    SinglyC();
    void Display();
    int Count();
    void InsertFirst(int);
    void InsertLast(int);
    void DeleteFirst();
    void DeleteLast();
    void InsertAtPosition(int, int);
    void DeleteAtPosition(int);
};
SinglyC::SinglyC()
{
    Head = NULL;
    Tail = NULL;
    Size = 0;
}
inline void SinglyC::Display()
{
    PNODE Temp = Head;
    PNODE Temp1 = Tail;

    do
    {
        cout << Temp->Data << "->";
        Temp = Temp->Next;

    } while (Temp1->Next != Temp);

    cout << "\n";
}

inline int SinglyC::Count()
{
    return Size;
}
void SinglyC::InsertFirst(int iNo)
{
    PNODE Temp = Head;
    PNODE Temp1 = Tail;
    PNODE Newn = new NODE;
    Newn->Next = NULL;
    Newn->Data = iNo;
    if ((Head == NULL) && (Tail == NULL))
    {
        Head = Newn;
        Tail = Newn;
    }
    else
    {
        Newn->Next = Head;
        Head = Newn;
    }
    Size++;
    Tail->Next = Head;
}
void SinglyC::InsertLast(int iNo)
{
    PNODE Newn = new NODE;
    Newn->Next = NULL;
    Newn->Data = iNo;
    PNODE Temp = Head;
    if ((Head == NULL) && (Tail == NULL))
    {
        Head = Newn;
        Tail = Newn;
    }
    else
    {

        Tail->Next = Newn;
        Tail = Newn;
    }
    Size++;
    Tail->Next = Head;
}
void SinglyC::DeleteFirst()
{
    PNODE Temp = Head;
    PNODE Temp1 = Tail;
    if ((Head == NULL) && (Tail == NULL))
    {
        return;
    }
    else if ((Head) == (Tail))
    {
        delete (Temp);
        (Temp) = NULL;
    }
    else
    {
        Head = Head->Next;
        delete (Temp);
    }
    Size--;
    Tail->Next = Head;
}
void SinglyC::DeleteLast()
{
    PNODE Temp = Head;
    if ((Head == NULL) && (Tail == NULL))
    {
        return;
    }
    else if (Temp->Next == Tail)
    {
        delete (Temp);
        Temp = NULL;
    }

    else
    {
        while (Temp->Next->Next != Tail->Next)
        {
            Temp = Temp->Next;
        }
        delete (Temp->Next);
        Tail = Temp;
    }
    Size--;
    Tail->Next = Head;
}
void SinglyC::InsertAtPosition(int iNo, int Pos)
{
    Size = Count();
    if ((Pos < 0) || (Pos > Size + 1))
    {
        return;
    }
    if (Pos == 1)
    {
        InsertFirst(iNo);
    }
    else if (Pos == Size + 1)
    {
        InsertLast(iNo);
    }
    else
    {
        PNODE Newn = new NODE;
        Newn->Data = iNo;
        Newn->Next = NULL;
        PNODE Temp = Head;
        for (int i = 1; i < Pos - 1; i++)
        {
            Temp = Temp->Next;
        }

        Newn->Next = Temp->Next;
        Temp->Next = Newn;
    }
    Size++;
    Tail->Next = Head;
}
void SinglyC::DeleteAtPosition(int Pos)
{
    Size = Count();
    if ((Pos < 0) || (Pos > Size + 1))
    {
        return;
    }
    if (Pos == 1)
    {
        DeleteFirst();
    }
    else if (Pos == Size)
    {
        DeleteLast();
    }
    else
    {
        PNODE Newn = new NODE;
        Newn->Next = NULL;
        PNODE Temp = Head;
        for (int i = 1; i < Pos - 1; i++)
        {
            Temp = Temp->Next;
        }
        PNODE Temp1 = Temp->Next;
        Temp->Next = Temp->Next->Next;
        delete (Temp1);
    }
    Size--;
    Tail->Next = Head;
}

///////////////////////////////////DOUBLy LINEAR LINKEDLIST//////////////

class DoublyL
{
private:
    PNODE Head;
    PNODE Tail;
    int Size;

public:
    DoublyL();
    void Display();
    int Count();
    void InsertFirst(int);
    void InsertLast(int);
    void DeleteFirst();
    void DeleteLast();
    void InsertAtPosition(int, int);
    void DeleteAtPosition(int);
};
DoublyL::DoublyL()
{
    Head = NULL;
    Tail = NULL;
    Size = 0;
}
inline void DoublyL::Display()
{
    PNODE Temp = Head;

    while (Temp != NULL)

    {
        cout << Temp->Data << "->";
        Temp = Temp->Next;
    }

    cout << "\n";
}

inline int DoublyL::Count()
{
    return Size;
}
void DoublyL::InsertFirst(int iNo)
{
    PNODE Temp = Head;
    PNODE Temp1 = Tail;
    PNODE Newn = new NODE;
    Newn->Next = NULL;
    Newn->Pre = NULL;
    Newn->Data = iNo;
    if ((Head == NULL))
    {
        Head = Newn;
    }
    else
    {
        Newn->Next = Head;
        Newn->Pre = NULL;
        Head = Newn;
    }
    Size++;
}
void DoublyL::InsertLast(int iNo)
{
    PNODE Newn = new NODE;
    Newn->Next = NULL;
    Newn->Pre = NULL;
    Newn->Data = iNo;
    PNODE Temp = Head;
    if ((Head == NULL))
    {
        Head = Newn;
    }
    else
    {
        while (Temp->Next != NULL)
        {
            Temp = Temp->Next;
        }
        Temp->Next = Newn;
        Newn->Pre = Temp;
        Newn->Next = NULL;
    }
    Size++;
}
void DoublyL::DeleteFirst()
{
    PNODE Temp = Head;
    if ((Head == NULL))
    {
        return;
    }
    else if ((Head->Next == NULL))
    {
        delete (Temp);
        (Temp) = NULL;
    }
    else
    {
        Head = Head->Next;
        delete (Temp);
    }
    Size--;
}
void DoublyL::DeleteLast()
{
    PNODE Temp = Head;
    if ((Head == NULL))
    {
        return;
    }
    else if (Temp->Next == NULL)
    {
        delete (Temp);
        Temp = NULL;
    }

    else
    {
        while (Temp->Next->Next != NULL)
        {
            Temp = Temp->Next;
        }
        delete (Temp->Next);
        Temp->Next = NULL;
    }
    Size--;
}
void DoublyL::InsertAtPosition(int iNo, int Pos)
{
    Size = Count();
    if ((Pos < 0) || (Pos > Size + 1))
    {
        return;
    }
    if (Pos == 1)
    {
        InsertFirst(iNo);
    }
    else if (Pos == Size + 1)
    {
        InsertLast(iNo);
    }
    else
    {
        PNODE Newn = new NODE;
        Newn->Data = iNo;
        Newn->Next = NULL;
        Newn->Pre = NULL;
        PNODE Temp = Head;
        for (int i = 1; i < Pos - 1; i++)
        {
            Temp = Temp->Next;
        }

        Newn->Next = Temp->Next;
        Temp->Next->Pre = Newn;
        Newn->Pre = Temp;
        Temp->Next = Newn;
    }
    Size++;
}
void DoublyL::DeleteAtPosition(int Pos)
{
    Size = Count();
    if ((Pos < 0) || (Pos > Size + 1))
    {
        return;
    }
    if (Pos == 1)
    {
        DeleteFirst();
    }
    else if (Pos == Size)
    {
        DeleteLast();
    }
    else
    {
        PNODE Newn = new NODE;
        Newn->Next = NULL;
        PNODE Temp = Head;
        for (int i = 1; i < Pos - 1; i++)
        {
            Temp = Temp->Next;
        }
        // PNODE Temp1 = Temp->Next;
        Temp->Next = Temp->Next->Next;
        delete (Temp->Next->Pre);
        Temp->Next->Pre = Temp;
    }
    Size--;
}

/////////////////////////////DOUBLE CIRCULAR LINKLIST///////////////////

class DoublyC
{
private:
    PNODE Head;
    PNODE Tail;
    int Size;

public:
    DoublyC();
    void Display();
    int Count();
    void InsertFirst(int);
    void InsertLast(int);
    void DeleteFirst();
    void DeleteLast();
    void InsertAtPosition(int, int);
    void DeleteAtPosition(int);
};
DoublyC::DoublyC()
{
    Head = NULL;
    Tail = NULL;
    Size = 0;
}
inline void DoublyC::Display()
{
    if ((Head == NULL) && (Tail == NULL))
    {
        return;
    }
    PNODE Temp = Head;
    PNODE Temp1 = Tail;

    do
    {
        cout << Temp->Data << "->";
        Temp = Temp->Next;

    } while (Temp != (Temp1->Next));

    cout << "\n";
}

inline int DoublyC::Count()
{
    return Size;
}
void DoublyC::InsertFirst(int iNo)
{
    PNODE Temp = Head;
    PNODE Temp1 = Tail;
    PNODE Newn = new NODE;
    Newn->Next = NULL;
    Newn->Pre = NULL;
    Newn->Data = iNo;
    if ((Head == NULL) && (Tail == NULL))
    {
        Head = Newn;
        Tail = Newn;
    }
    else
    {
        Newn->Next = Head;
        Head = Newn;
    }
    Size++;
    Tail->Next = Head;
    Head->Pre = Tail;
}
void DoublyC::InsertLast(int iNo)
{
    PNODE Newn = new NODE;
    Newn->Next = NULL;
    Newn->Pre = NULL;
    Newn->Data = iNo;
    PNODE Temp = Head;
    if ((Head == NULL) && (Tail == NULL))
    {
        Head = Newn;
        Tail = Newn;
    }
    else
    {
        Newn->Pre = Tail;
        Newn->Next = Head;
        Tail->Next = Newn;
        Tail = Newn;
    }
    Size++;
    Tail->Next = Head;
    Head->Pre = Tail;
}
void DoublyC::DeleteFirst()
{
    PNODE Temp = Head;
    PNODE Temp1 = Tail;
    if ((Head == NULL) && (Tail == NULL))
    {
        return;
    }
    else if ((Head) == (Tail))
    {
        delete (Temp);
        (Temp) = NULL;
    }
    else
    {
        Head = Head->Next;
        delete (Temp);
    }
    Size--;
    Tail->Next = Head;
    Head->Pre = Tail;
}
void DoublyC::DeleteLast()
{
    PNODE Temp = Head;
    if ((Head == NULL) && (Tail == NULL))
    {
        return;
    }
    else if (Temp->Next == Tail)
    {
        delete (Temp);
        Temp = NULL;
    }

    else
    {
        Tail = Tail->Pre;
        delete (Tail->Next);
    }
    Size--;
    Tail->Next = Head;
    Head->Pre = Tail;
}
void DoublyC::InsertAtPosition(int iNo, int Pos)
{
    Size = Count();
    if ((Pos < 0) || (Pos > Size + 1))
    {
        return;
    }
    if (Pos == 1)
    {
        InsertFirst(iNo);
    }
    else if (Pos == Size + 1)
    {
        InsertLast(iNo);
    }
    else
    {
        PNODE Newn = new NODE;
        Newn->Data = iNo;
        Newn->Next = NULL;
        Newn->Pre = NULL;
        PNODE Temp = Head;
        for (int i = 1; i < Pos - 1; i++)
        {
            Temp = Temp->Next;
        }

        Newn->Next = Temp->Next;
        Newn->Pre = Temp;
        Temp->Next = Newn;
        Temp->Next->Pre = Newn;
    }
    Size++;
    Tail->Next = Head;
    Head->Pre = Tail;
}
void DoublyC::DeleteAtPosition(int Pos)
{
    Size = Count();
    if ((Pos < 0) || (Pos > Size + 1))
    {
        return;
    }
    if (Pos == 1)
    {
        DeleteFirst();
    }
    else if (Pos == Size)
    {
        DeleteLast();
    }
    else
    {
        PNODE Newn = new NODE;
        Newn->Next = NULL;
        Newn->Pre = NULL;
        PNODE Temp = Head;
        for (int i = 1; i < Pos - 1; i++)
        {
            Temp = Temp->Next;
        }

        Temp->Next = Temp->Next->Next;
        delete (Temp->Next->Pre);
        Temp->Next->Pre = Temp;
    }
    Size--;
    Tail->Next = Head;
    Head->Pre = Tail;
}

int main()
{
    //int Choice = 1;
    //int iNo = 0;
    int iNo = 0, iRet = 0, Pos = 0;

    int Choice = 1;
    while (Choice)
    {
        cout << "ENTER CHOOICE\n";

        cout << "---------------------------------\n";

        cout << "1: SINGALY LINEAR LINKEDLIST\n";
        cout << "2: SINGALY CIRCULAR LINKEDLIST\n";
        cout << "3: DOUBLE LENEAR LINKEDLIST\n";
        cout << "4: DOUBLE CIRCLULR LINKEDLIST\n";
        cout << "0: EXIT FROM APPILICATION\n";

        cout << "---------------------------------\n";

        cin >> Choice;

        switch (Choice)

        {
        case 1:
        {
            SinglyL obj;

            cout << "-------------------------------------------\n";
            cout << "SINGLY  LINEAR LINKEDLIST\n";
            cout << "-------------------------------------------\n";

            while (Choice)
            {
                cout << "ENTER CHOICE\n";

                cout << "1 : InsertFirst\n";
                cout << "2 : InsertLast\n";
                cout << "3 : DeleteFirst\n";
                cout << "4 : DeleteLast\n";
                cout << "5 : InsertAtPosition\n";
                cout << "6 : DeleteAtPosition\n";
                cout << "7 : Display\n";
                cout << "8 : Count\n";
                cout << "0 : EXIT\n";

                cin >> Choice;

                switch (Choice)
                {
                case 1:
                    cout << "ENTER NUMBER\n";
                    cin >> iNo;
                    obj.InsertFirst(iNo);
                    break;
                case 2:
                    cout << "ENTER NUMBER\n";
                    cin >> iNo;
                    obj.InsertLast(iNo);
                    break;
                case 3:
                    obj.DeleteFirst();
                    break;
                case 4:
                    obj.DeleteLast();
                    break;
                case 5:
                    cout << "ENTER NUMBER\n";
                    cin >> iNo;
                    cout << "ENTER POSITIOBN\n";
                    cin >> Pos;
                    obj.InsertAtPosition(iNo, Pos);
                    break;
                case 6:
                    cout << "ENTER POSITIOBN\n";
                    cin >> Pos;
                    obj.DeleteAtPosition(Pos);
                    break;
                case 7:
                    obj.Display();
                    break;
                case 8:
                    iRet = obj.Count();
                    cout << "THE NODES IN LINKEDLIST ARE---->>" << iRet << endl;
                    break;
                case 0:
                    cout << "THABKS FOR USING THIS APPLICATION\n";
                    break;
                default:
                    cout << "ERROR:WRONG INPUT\n";
                    break;
                }
            }
            break;
        }

        case 2:
        {
            int Choice = 1;
            int iNo = 0;
            SinglyC obj;

            cout << "-------------------------------------------\n";
            cout << "SINGLY CIRCULAR LINKEDLIST\n";
            cout << "-------------------------------------------\n";

            while (Choice)
            {
                cout << "ENTER CHOICE\n";

                cout << "1 : InsertFirst\n";
                cout << "2 : InsertLast\n";
                cout << "3 : DeleteFirst\n";
                cout << "4 : DeleteLast\n";
                cout << "5 : InsertAtPosition\n";
                cout << "6 : DeleteAtPosition\n";
                cout << "7 : Display\n";
                cout << "8 : Count\n";
                cout << "0 : EXIT\n";

                cin >> Choice;

                switch (Choice)
                {
                case 1:
                    cout << "ENTER NUMBER\n";
                    cin >> iNo;
                    obj.InsertFirst(iNo);
                    break;
                case 2:
                    cout << "ENTER NUMBER\n";
                    cin >> iNo;
                    obj.InsertLast(iNo);
                    break;
                case 3:
                    obj.DeleteFirst();
                    break;
                case 4:
                    obj.DeleteLast();
                    break;
                case 5:
                    cout << "ENTER NUMBER\n";
                    cin >> iNo;
                    cout << "ENTER POSITIOBN\n";
                    cin >> Pos;
                    obj.InsertAtPosition(iNo, Pos);
                    break;
                case 6:
                    cout << "ENTER POSITIOBN\n";
                    cin >> Pos;
                    obj.DeleteAtPosition(Pos);
                    break;
                case 7:
                    obj.Display();
                    break;
                case 8:
                    iRet = obj.Count();
                    cout << "THE NODES IN LINKEDLIST ARE---->>" << iRet << endl;
                    break;
                case 0:
                    cout << "THABKS FOR USING THIS APPLICATION\n";
                    break;
                default:
                    cout << "ERROR:WRONG INPUT\n";
                    break;
                }
            }
            break;
        }

        case 3:
        {
            int iNo = 0, iRet = 0, Pos = 0;

            int Choice = 1;

            DoublyL obj;

            cout << "-------------------------------------------\n";
            cout << "Doubly LINEAR LINKEDLIST\n";
            cout << "-------------------------------------------\n";

            while (Choice)
            {
                cout << "ENTER CHOICE\n";

                cout << "1 : InsertFirst\n";
                cout << "2 : InsertLast\n";
                cout << "3 : DeleteFirst\n";
                cout << "4 : DeleteLast\n";
                cout << "5 : InsertAtPosition\n";
                cout << "6 : DeleteAtPosition\n";
                cout << "7 : Display\n";
                cout << "8 : Count\n";
                cout << "0 : EXIT\n";

                cin >> Choice;

                switch (Choice)
                {
                case 1:
                    cout << "ENTER NUMBER\n";
                    cin >> iNo;
                    obj.InsertFirst(iNo);
                    break;
                case 2:
                    cout << "ENTER NUMBER\n";
                    cin >> iNo;
                    obj.InsertLast(iNo);
                    break;
                case 3:
                    obj.DeleteFirst();
                    break;
                case 4:
                    obj.DeleteLast();
                    break;
                case 5:
                    cout << "ENTER NUMBER\n";
                    cin >> iNo;
                    cout << "ENTER POSITIOBN\n";
                    cin >> Pos;
                    obj.InsertAtPosition(iNo, Pos);
                    break;
                case 6:
                    cout << "ENTER POSITIOBN\n";
                    cin >> Pos;
                    obj.DeleteAtPosition(Pos);
                    break;
                case 7:
                    obj.Display();
                    break;
                case 8:
                    iRet = obj.Count();
                    cout << "THE NODES IN LINKEDLIST ARE---->>" << iRet << endl;
                    break;
                case 0:
                    cout << "THABKS FOR USING THIS APPLICATION\n";
                    break;
                default:
                    cout << "ERROR:WRONG INPUT\n";
                    break;
                }
            }
            break;
        }

        case 4:
        {
            int iNo = 0, iRet = 0, Pos = 0;

            int Choice = 1;

            DoublyC obj;

            cout << "-------------------------------------------\n";
            cout << "    DoublyC CIRCULAR LINKEDLIST\n";
            cout << "-------------------------------------------\n";

            while (Choice)
            {
                cout << "ENTER CHOICE\n";

                cout << "1 : InsertFirst\n";
                cout << "2 : InsertLast\n";
                cout << "3 : DeleteFirst\n";
                cout << "4 : DeleteLast\n";
                cout << "5 : InsertAtPosition\n";
                cout << "6 : DeleteAtPosition\n";
                cout << "7 : Display\n";
                cout << "8 : Count\n";
                cout << "0 : EXIT\n";

                cin >> Choice;

                switch (Choice)
                {
                case 1:
                    cout << "ENTER NUMBER\n";
                    cin >> iNo;
                    obj.InsertFirst(iNo);
                    break;
                case 2:
                    cout << "ENTER NUMBER\n";
                    cin >> iNo;
                    obj.InsertLast(iNo);
                    break;
                case 3:
                    obj.DeleteFirst();
                    break;
                case 4:
                    obj.DeleteLast();
                    break;
                case 5:
                    cout << "ENTER NUMBER\n";
                    cin >> iNo;
                    cout << "ENTER POSITIOBN\n";
                    cin >> Pos;
                    obj.InsertAtPosition(iNo, Pos);
                    break;
                case 6:
                    cout << "ENTER POSITIOBN\n";
                    cin >> Pos;
                    obj.DeleteAtPosition(Pos);
                    break;
                case 7:
                    obj.Display();
                    break;
                case 8:
                    iRet = obj.Count();
                    cout << "THE NODES IN LINKEDLIST ARE---->>" << iRet << endl;
                    break;
                case 0:
                    cout << "THABKS FOR USING THIS APPLICATION\n";
                    break;
                default:
                    cout << "ERROR:WRONG INPUT\n";
                    break;
                }
            }
            break;
        }
        case 0:
        {
            cout << "\nTHANKS FOR USING THIS APPLICATION\n";
            break;
        }
        default:
        {
            cout << "ERROR::WRONG INPUT";
            break;
        }
        }
    }
    return 0;
}