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
        check removes at boundaries
    */
    list->insert(0,"Gandalf");
    list->insert(1,"Devin");
    list->insert(2,"Ron");
    list->insert(3,"Hi");

    list->remove(3);
    //cout<<"should not be a node at 3 and it is core dumped: "<<endl;
    //cout<<list->get(3)<<endl;
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




    /*
        check getNodeAt boundaries and middle and when there is an empty list
    */
    /*list->insert(0, "Gandalf");
    list->insert(0, "Dev");*/

    /*if(list->get(0) == "Dev"){cout<<"SUCCESS-------"<<endl;}
    else{cout<<"FAIL------DEV ISNT AT 0"<<endl;}

    if(list->get(1) == "Gandalf"){cout<<"WOOOO Gandalf is at pos 1";}
    else{cout<<"FAIL------Gandalf ISNT AT 1";}*/


    /*list->remove(0);
    //cout<<"I guess I removed Devin"<<endl;
    cout<<"node at pos 0 is: "<<list->get(0); //PROBLEM WITH GETTING AT the position i removed
    if(list->get(0)=="Gandalf"){cout<<"REMOVE SUCCESS -- removed Devin and moved Gandalf over"<<endl;}
    else{cout<<"REMOVE FAIL --- Devin is still there!"<<endl;}*/

    /*list->get(1);
    //if(list->get(1)=="Gandalf"){cout<<"there is no position 1";}
    //else{cout<<"FAIL the position is messed up"<<endl;}
    list->remove(2);
     list->insert(3, "R");
     list->insert(0, "D");
    //list->insert(1, "Devin");
     list->insert(0, "ron");
     list->insert()*/
    /*list->insert(3,"R"); //shouldnt insert anything because there is no position there

    list->insert(0,"D");

    list->insert(1,"E");

    list->insert(2,"GR");

    list->insert(3,"F");

    list->remove(3);

    list->remove(4);*/

    /*cout<<"size is: "<<list->size()<<endl;

    //list->getNodeAt(2);

    list->insert(3,"G");

    list->insert(4, "H");

    if(!list->empty()){
     cout<<"Not Empty! list is size: "<<list->size()<<endl;
    }
    else{
     cout<<"FAIL. Why is it empty??"<<endl;
    //}
    // Check if the list is still empty.
    if (!list->empty()) {
     cout << "SUCCESS: List is not empty after one insertion." << endl;
    } else {
     cout << "FAIL: List is empty after one insertion." << endl;
    }

    if (list->size() == 1) {
     cout << "SUCCESS: List has size 1 after one insertion." << endl;
    } else {
     cout << "FAIL: List has size " << list->size() << " after one insertion.";
     cout << endl;
    }

    // Check if the value is correct.
    if (list->get(0) == "Gandalf") {
     cout << "SUCCESS: 3 is at the 0th index of the list." << endl;
    } else {
     cout << "FAIL: 3 is not at the 0th index of the list, " << list->get(0);
     cout << " is instead." << endl;
    }*/

    // TODO: Continue adding tests for your program, or start your own file with your
    // own tests. Remember to submit a file that is named correctly!

    // Clean up memory.
    delete list;
    return 0;
    //}
}