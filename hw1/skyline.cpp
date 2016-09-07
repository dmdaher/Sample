#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char* argv[])
{
    if(argc < 3) {
        cerr << "Please provide an input and output file." << endl;
        return 1;
    }
    ifstream input(argv[1]);
    ofstream output(argv[2]);
    int constructionspots;
    int *buildingheights;
    string **skyline;
    string curr;
    stringstream spots;
    input >> constructionspots;
    if (input.fail() || constructionspots<=0)
    {
        output << "Error - incorrect command"<<endl;
        return 1;
    }
    getline(input, curr); //consume the newline character for the first line.
    skyline = new string*[constructionspots]; //declaring pointer to an array of total number con. spots

    //you will need to keep track of the height of each building
    buildingheights = new int[constructionspots];
    for (int i = 0; i < constructionspots; i++) {
        buildingheights[i] = 0; //initializing all buildings to 0 height
        skyline[i] = NULL; //points to no buildings. initializing pointer
    }
    while(getline(input, curr)) {
        stringstream ss;
        ss << curr; //getline grabbed the whole line so the long string curr is putting everything into the stream and then next,
        ss >> curr;//the stream is giving curr the first word in the stream
        if (curr == "BUILD") {
            int x,y; //x is the construction spot and y is the height
            string c; //c is the color
            ss >> x;
            ss >> y;
            ss >> c;
            if (ss.fail() || skyline[x] != NULL ||x>=constructionspots || x<0 || y<1) {
                output << "Error - incorrect command" << endl;
                return 1;
            }
            else
            {
                buildingheights[x] = y; //at spot x, height is y
                skyline[x] = new string[buildingheights[x]];
                for (int i = 0; i< y; i++)
                {
                    skyline[x][i] = c;
                }
            }
        }

        else if (curr == "EXTEND")
        {
            int x,y; //x is the construction spot and y is the height
            string c; //c is the color
            ss >> x;
            ss >> y;
            ss >> c;
            if (ss.fail()||skyline[x] == NULL || x>=constructionspots || x<0 || y<1)
            {
                output << "Error - incorrect command" << endl;
                return 1;
            }
            else
            {
                int newHeight = y + buildingheights[x];
                int initialbuildingheight = buildingheights[x];
                buildingheights[x] = newHeight;
                string* tempsky = new string[newHeight];
                for (int i = 0; i < initialbuildingheight; i++)
                {
                    tempsky[i] = skyline[x][i];
                }
                for (int i = initialbuildingheight; i<newHeight; i++)
                {
                    tempsky[i] = c;
                }
                skyline[x] = tempsky;
            }

        }

        else if (curr == "DEMOLISH")
        {
            int x; //x is the construction spot and y is the height
            ss >> x;
            if (ss.fail() || skyline[x] == NULL || x>=constructionspots || x<0)
            {
                output << "Error - incorrect command" << endl;
                return 1;
            }
            else
            {
                skyline[x] = NULL;
                buildingheights[x] = 0;
            }

        }

        else if (curr == "SKYLINE")
        {
            int y;
            ss >> y;
            if (ss.fail() || y<1)
            {
                output << "Error - incorrect command"<<endl;
                return 1;
            }
            for (int i = 0; i<constructionspots; i++)
            {
                if(buildingheights[i] < y)
                {
                    string sky = "SKY";
                    output << sky << " ";
                }
                else
                {
                    if (skyline[i] != NULL && buildingheights[i] >= y)
                    {
                        output << skyline[i][y-1] << " ";
                    }
                    else
                    {
                        output << "Error - incorrect command"<<endl;
                    }
                }
            }

        }
        else {
            output << "Error - No command"<<endl;
            return 1;
        }
    }
    for (int i = 0; i<constructionspots; i++)
    {
        delete [] skyline[i];
    }
    delete [] skyline;
    delete [] buildingheights;
    return 0;
}