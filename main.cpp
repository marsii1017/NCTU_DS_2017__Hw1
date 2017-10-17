// reading a text file

 	#include <string>
	#include <fstream>
	#include <sstream>
	#include <vector>
	#include <iostream>
	#include <iomanip>
    #include<deque>
    #include <algorithm>

    using namespace std;
    int i;
	int main(int argc, char** argv)
	{
	    ifstream in(argv[1]); //"case1.txt"
	    string strLine;
	    deque<deque<string> > Data2D;
	    deque<deque<string> > direction;
        int exchange_end;
	    int row_num=0;
	    int data_num=0;
	    int infor_end=0;
	    while (getline(in, strLine))
	    {

	        stringstream ss(strLine);
	        deque<string> row;
	        string data;
	        while (ss >> data)
	        {
               if(data=="#"){
                    infor_end=1;
                    data_num= row_num;  //There has data_num rows.
               }
               else{

            //    cout<<"print"<<" ";
                    row.push_back(data);

               }
	        }
	               if(data!="#"){
                        if( infor_end==0){
                                Data2D.push_front(row);
                                row_num++;
                     }
                     else {
                                direction.push_back(row);
                     }
	               }
	       // else
          //  direction.push_back(row);
	    }
        // there has row_num rows
      //  cout<<row_num;
        int num[row_num]={0};
	     for (size_t r = 0; r < Data2D.size(); r++)
	    {
	        //num[r]=0
	        for (size_t c = 0; c < Data2D[r].size(); c++)
	        {
	            cout << Data2D[r][c]<<" ";
	            num[r]++;
	        }
	        cout << endl;
	    }
	    for(int z=0;z<row_num;z++){
            cout<< num[z]<<" ";
	    }
	    cout<<"\n";
      //  cout<<row_num;
        //cout<<data_num<<"\n";
        cout<<"direction:"<<endl;
            for (size_t r = 0; r < direction.size(); r++)      //beginning of print direction
	    {
	        for (size_t c = 0; c < direction[r].size(); c++)
	        {
	            cout << direction[r][c]<<" ";

	        }
	        cout << endl;
	    }                                                                    //end of /printing direction
        cout<<"Data2D[0][0]:"<<Data2D[0][0]<<"\n";
        stringstream c;
        int tempc;
        c<<direction[0][0];
        c>>tempc;
        cout<<"direction[0][0]:"<<tempc<<"\n";
    //    cout<<"Data2D[0][0][0]"<<Data2D[0][0][0]<<"\n";


        //////////////////////////////////////////direction loop  begin//////////////////

        int direction_1,direction_2,max_push,min_push;
           cout<<direction.size()<<"\n";
    for( int j=0;j<direction.size();j++){

        direction_1=stoi(direction[j][0]);
        cout<<"direction["<<"i"<<"][0]" <<direction_1<<"\n";
        direction_2=stoi(direction[j][1]);
        cout<<"direction["<<"i"<<"][0]" <<direction_2<<"\n\n";
       ////////////////////////////////temp queque   input /////////////
       deque<deque<string>>temp_queue;
       deque <string> tempstring;
        max_push=max(direction_1,direction_2);
        min_push=min(direction_1,direction_2);
        cout<<"min_push="<<min_push<<"\n";
        for( i= 0;i<max_push;i++){
              if(i==(max_push-1)){
              //   cout<<"baby"<<"\n";
              }
              else if(i==(min_push-1)){
            //     cout<<"baby"<<"\n";
              }
              else {
                    tempstring=Data2D[i];
                   temp_queue.push_back(tempstring);
              }
        }

         ///////////////////////////////////////  compare!!!!!!!////////////////////
          deque<string> compar_a,compar_b;
            for (deque<string>::iterator it = Data2D[direction_1-1].begin(); it!=Data2D[direction_1-1].end(); ++it){
               compar_a.push_front(*it);
            }
            for(deque<string>::iterator it = Data2D[direction_2-1].begin(); it!=Data2D[direction_2-1].end(); ++it){
                compar_b.push_front(*it);
            }
            cout<<"compar_a: ";
            for (deque<string>::iterator it = compar_a.begin(); it!=compar_a.end(); ++it){    //print result of push_back in temp
                cout<<*it<<" ";
            }
            cout<<"\n";
            cout<<"compar_b: ";
            for(deque<string>::iterator it = compar_b.begin(); it!=compar_b.end(); ++it){
            cout<<*it<<" ";
            }
           for(deque<string>::iterator it = compar_b.begin(); it!=compar_b.end(); ++it){
                if((compar_a[0][0]==(*it)[0] )||(compar_a[0][1]==(*it)[1] ))
                {
                    compar_a.push_front((*it));
                    exchange_end=0;                 // after this movement, temp goes into stack.

                }
                else{
                    compar_a.push_back((*it));
                    exchange_end=1;                  // after this movement, compar goes into stack.

                }
            }
                          ////////////////////////      total compar_a       /////////
            cout<<"\n"<<"new_compar(by reverse):";
            reverse(compar_a.begin(),compar_a.end());            //////reverse compar_a
           for(deque<string>::iterator it = compar_a.begin(); it!=compar_a.end(); ++it){
                 cout<<*it<<" ";
            }
            cout<<"\n";
            /////////////////////////////// erase is completed.////////
    //    cout<<"exchange_end:"<<exchange_end<<"\n";
        for(i=0;i<max_push;i++){
          Data2D.erase ( Data2D.begin());
        }
        cout<<"hello:::::"<<i;
     //     Data2D.erase ( Data2D.begin()+direction_2-1);

            ///////////////////// determine  Sort push_front  push_back to Data2D stack
            if(exchange_end==0){                       ///temp goes into the stack.
                Data2D.push_front(compar_a);
                for( i=0;i<temp_queue.size();i++){
                    Data2D.push_front(temp_queue[i]);
               //     cout<<"exchange=0";
                }

            }

            else{                                              ////// exchange=1

                    for( i=0;i<temp_queue.size();i++){
                    Data2D.push_front(temp_queue[i]);
                //    cout<<"exchange=1";
                }
                  Data2D.push_front(compar_a);
            }
        //////////////////////// print Data2D//////////////
         deque< deque<string> >::iterator row;
         deque<string>::iterator col;
         cout<<"Data2D now: ";
                for (row = Data2D.begin(); row != Data2D.end(); row++) {
                    for (col = row->begin(); col != row->end(); col++) {
                    cout<<(*col)<<" ";
                    }
                cout<<"\n";
                }
                cout<<"data2d size="<<Data2D.size()<<"\n";
        ///////////////////////////clear temp compar,comparb////////////////////
            compar_a.clear();
            compar_b.clear();
            temp_queue.clear();
     }
      reverse(Data2D[0].begin(),Data2D[0].end());
        for (deque<string>::iterator it = Data2D[0].begin(); it!=Data2D[0].end(); ++it){
                                cout<<*it<<" ";
            }
        ofstream myfile;
        myfile.open (argv[2]);//"example.txt"
        for (deque<string>::iterator it = Data2D[0].begin(); it!=Data2D[0].end(); ++it){
                         myfile <<*it<<" ";
            }
        myfile.close();
        in.close();
	}
