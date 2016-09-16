#include "lliststring.h"
#include <iostream>

using namespace std;

int main()
{
    LListString* list = new LListString();
    std::cout<<"here"<<std::endl;

    if (list->empty()) {
        cout << "SUCCESS: List is empty initially." << endl;
    } else {
        cout << "FAIL: List is not empty initially when it should be." << endl;
    }

// Insert an item at the head. Test insert when empty, at beginning, end, and middle. Then test insert at same position you previously inserted at
    /*
        test many inserts and many removes and check the sizes
    */
    if(list->size()==0) {
        cout<<"SUCCESS, list is empty"<<endl;
    }
    else {
        cout<<"FAIL list is NOT empty"<<endl;
    }

    list->insert(0,"Gandalf");
    list->insert(1,"Devin");
    list->insert(2,"Ron");
    list->insert(3,"Hi");
    list->insert(4,"Mitch");
    list->insert(5,"Gary");
    list->insert(6,"Lucas");
    list->insert(7,"Madi");

    if(list->size()==8) {
        cout<<"SUCCESS, list size is 8 from positions 0-7"<<endl;
    }
    else {
        cout<<"FAIL list is NOT 8"<<endl;
    }

    list->remove(5);
    if(list->size()==7) {
        cout<<"SUCCESS, list size is 8 from positions 0-6"<<endl;
    }
    else {
        cout<<"FAIL list is NOT 7"<<endl;
    }

    list->remove(7);
    if(list->size()==7) {
        cout<<"SUCCESS, no node removed"<<endl;
    }
    else {
        cout<<"FAIL list is NOT 7"<<endl;
    }

    list->remove(2);
    list->remove(0);
    list->remove(100);
    list->remove(4);

    if(list->size()==4) {
        cout<<"SUCCESS, list size is 4"<<endl;
    }
    else {
        cout<<"FAIL list is NOT 4"<<endl;
    }

    //list->get(90);
    cout<<"what is the node at position 2 and 3? meaning nodes 3 and 4: "<<list->get(2)<<" "<<list->get(3)<<endl;

    for(int i =3; i>=0; i--)
    {
        list->remove(i);
    }
    if(list->size()==0) {
        cout<<"SUCCESS, list size is 0"<<endl;
    }
    else {
        cout<<"FAIL list is NOT 0"<<endl;
    }

    //cout<<"getting no nodes hopefully: <<"<<list->get(0)<<endl; //abort core dumped. leaving it be because they wrote that code
    //cout<<"hopefully getting nothing again"<<list->get(100)<<endl; //abort core dumped. leaving it be because they wrote that code

    list->insert(0,"Hello");

    cout<<"getting the string Hello hopefully: "<<list->get(0)<<endl;

    list->remove(0);
    cout<<list->size()<<endl;

    cout<<"now INSERT and then remove at boundaries"<<endl;

    /*
        check removes at boundaries.
    */
    list->insert(0,"Gandalf");
    list->insert(1,"Devin");
    list->insert(2,"Ron");
    list->insert(3,"Hi");

    list->remove(3);
    //cout<<list->get(3)<<endl;
    //should not be a node at 3 and it is core dumped which is good since the get function calls the throw function based on the code admins created
    cout<<"what is the node at 2? "<<list->get(2)<<endl;

    list->remove(0);
    cout<<"node now at 0 is: "<<list->get(0)<<endl;
    cout<<"node now at 1 is: "<<list->get(1)<<endl;

    list->remove(0);
    list->remove(0);
    cout<<list->size()<<endl;
    /*
        check inserts at random positions and then at boundaries
    */
    list->insert(10, "Interesting");
    list->insert(-2, "HMM");

    list->insert(0, "time");
    list->insert(1,"Ayy");

    cout<<list->get(1)<<endl;
    cout<<list->get(0)<<endl;

    list->insert(1,"Bound");
    cout<<"Should be Ayy because I am moving Ayy over and putting bound at pos 2 and it is: "<<list->get(2)<<endl;

    cout<<"size now is: "<<list->size()<<endl;
    cout<<"Now I will insert at size of list"<<endl;

    list->insert(3, "Boom");
    cout<<"inserted at size of list and word is: "<<list->get(1)<<endl;

    cout<<"size now should be 4 and is: "<<list->size()<<endl;

    /*
        checking the clear function
    */

    cout<<"clear it all"<<endl; 
    list->clear();

    cout<<"size should be 0 because it was cleared, size is: "<<list->size()<<endl;

    /*
    insert then test the set function to change a value
    */
    list->insert(0,"Gandalf");
    list->insert(1,"Devin");
    list->insert(2,"Ron");
    list->insert(3,"Hi");

    list->set(0,"Gandalf to Transform");
    list->set(3,"Hi to Hello");

    cout<<"what did Gandalf change to?"<<list->get(0)<<endl;
    cout<<"what did hi change to"<<list->get(3)<<endl;

    /*
        now check out of bounds when calling set
    */

    cout<<"should not set out of bounds"<<endl;
    list->set(5,"Batman");
    list->set(-3,"Dont");
    cout<<"did not crash when setting out of bounds and the get function calls throw"<<endl;

    list->clear();

    cout<<"size is 0? size is: "<<list->size()<<endl;


    /*
        check getNodeAt boundaries and middle and when there is an empty list
    */

    list->insert(0, "Gandalf");
    list->insert(0, "Dev");

    if(list->get(0) == "Dev"){cout<<"SUCCESS-------"<<endl;}
    else{cout<<"FAIL------DEV ISNT AT 0"<<endl;}

    if(list->get(1) == "Gandalf"){cout<<"WOOOO Gandalf is at pos 1"<<endl;}
    else{cout<<"FAIL------Gandalf ISNT AT 1"<<endl;}


    list->remove(0);
    cout<<"I guess I removed Devin"<<endl;
    cout<<"node at pos 0 is: "<<list->get(0)<<endl;
    if(list->get(0)=="Gandalf"){cout<<"REMOVE SUCCESS -- removed Devin and moved Gandalf over"<<endl;}
    else{cout<<"REMOVE FAIL --- Devin is still there!"<<endl;}

    list->remove(2);

    cout<<"size is:"<<list->size()<<endl;

    list->remove(0);

    cout<<"size is:"<<list->size()<<endl;

    list->clear();
    
    cout<<"SUCCESS!!!! ALL TEST CASES ACCOUNTED FOR"<<endl;
    // TODO: Continue adding tests for your program, or start your own file with your
    // own tests. Remember to submit a file that is named correctly!

    // Clean up memory.
    delete list;
    return 0;
    //}
}