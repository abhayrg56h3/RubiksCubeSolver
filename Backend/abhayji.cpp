
#ifndef ORDERED_SET_ALIAS
#define ORDERED_SET_ALIAS

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#endif // ORDERED_SET_ALIAS

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <climits>
#include <unordered_set>
#include <unordered_map>
#include <array>
#include <forward_list>
#include <algorithm>
#include <utility>
#include <functional>
#include <iterator>
#include <numeric>
#include <string>
#include <cctype>
#include <cstring>
#include <memory>
#include <new>
#include <algorithm>
#include <chrono>
#include <ctime>
#include <cmath>
#include <complex>
#include <random>
#include <limits>
#include <thread>
#include <mutex>
#include <atomic>
#include <future>
#include <condition_variable>
#include <exception>
#include <stdexcept>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <typeinfo>
#include <type_traits>
#include <initializer_list>
#include <tuple>
#include <bitset>
#include <regex>
#include <locale>




using namespace std;






struct Pos {
    int x, y, z; // each in {-1,0,1}
};
  string scramble ;

map<int,vector<char>>pos_to_piece;
map<vector<char>,int>piece_to_pos;
vector<Pos> indexToPos(28);


vector<string>ans;


void handleRotationAndUpdate(const std::string rot, std::string &scramble) {
             vector<vector<char>>face0(9,vector<char>(9));
               vector<vector<char>>face1(9,vector<char>(9));
                 vector<vector<char>>face2(9,vector<char>(9));
                   vector<vector<char>>face3(9,vector<char>(9));
                     vector<vector<char>>face4(9,vector<char>(9));
                       vector<vector<char>>face5(9,vector<char>(9));


                       for(int i=0;i<54;i++){
                          if(i/9==0){
                                 face0[i/3][i%3]=scramble[i];
                          }
                          else if(i/9==1){
  face1[(i-9)/3][i%3]=scramble[i];
                          }
                          else if(i/9==2){
 face2[(i-18)/3][i%3]=scramble[i];
                          }
                          else if(i/9==3){
face3[(i-27)/3][i%3]=scramble[i];
                          }
                          else if(i/9==4){
 face4[(i-36)/3][i%3]=scramble[i];
                          }
                          else{
face5[(i-45)/3][i%3]=scramble[i];
                          }
                       }


            vector<vector<char>>tmpface0=face0;
            vector<vector<char>>tmpface1=face1;
            vector<vector<char>>tmpface2=face2;
            vector<vector<char>>tmpface3=face3;
            vector<vector<char>>tmpface4=face4;
            vector<vector<char>>tmpface5=face5;




                       if(rot=="U"){
                            for(int i=0;i<3;i++){
                                for(int j=0;j<3;j++){
                                    tmpface0[j][2-i]=face0[i][j];
                                }
                            }
                            for(int j=0;j<3;j++){
                                tmpface1[0][j]=face5[0][j];
                            }
                            for(int j=0;j<3;j++){
                                tmpface2[0][j]=face1[0][j];
                            }
                            for(int j=0;j<3;j++){
                                tmpface4[0][j]=face2[0][j];
                            }
                            for(int j=0;j<3;j++){
                                tmpface5[0][j]=face4[0][j];
                            }
                       }
                       else if(rot=="D"){
for(int i=0;i<3;i++){
                                for(int j=0;j<3;j++){
                                    tmpface3[j][2-i]=face3[i][j];
                                }
                            }

                            for(int j=0;j<3;j++){
                                tmpface1[2][j]=face2[2][j];
                            }
                            for(int j=0;j<3;j++){
                                tmpface5[2][j]=face1[2][j];
                            }
                            for(int j=0;j<3;j++){
                                tmpface4[2][j]=face5[2][j];
                            }
                            for(int j=0;j<3;j++){
                                tmpface2[2][j]=face4[2][j];
                            }
                       }


                       else if(rot=="R"){
                            for(int i=0;i<3;i++){
                                for(int j=0;j<3;j++){
                                    tmpface1[j][2-i]=face1[i][j];
                                }
                            }

                            for(int i=0;i<3;i++){
                                tmpface2[i][2]=face3[i][2];
                            }
                           for(int i=0;i<3;i++){
                                tmpface3[i][2]=face5[2-i][0];
                            }
                            for(int i=0;i<3;i++){
                                tmpface5[2-i][0]=face0[i][2];
                            }
                            for(int i=0;i<3;i++){
                                tmpface0[i][2]=face2[i][2];
                            }

                       }


                           else if(rot=="L"){
                            for(int i=0;i<3;i++){
                                for(int j=0;j<3;j++){
                                    tmpface4[j][2-i]=face4[i][j];
                                }
                            }

                            for(int i=0;i<3;i++){
                                tmpface2[i][0]=face0[i][0];
                            }
                           for(int i=0;i<3;i++){
                                tmpface0[i][0]=face5[2-i][2];
                            }
                            for(int i=0;i<3;i++){
                                tmpface5[i][2]=face3[2-i][0];
                            }
                            for(int i=0;i<3;i++){
                                tmpface3[i][0]=face2[i][0];
                            }

                       }


                       
                           else if(rot=="F"){
                            for(int i=0;i<3;i++){
                                for(int j=0;j<3;j++){
                                    tmpface2[j][2-i]=face2[i][j];
                                }
                            }

                           
                                for(int i=2;i>=0;i--){
                                        tmpface0[2][2-i]=face4[i][2];
                                }
                            
                            for(int i=2;i>=0;i--){
                                        tmpface1[i][0]=face0[2][i];
                                }
                            for(int i=0;i<3;i++){
                                tmpface3[0][i]=face1[2-i][0];
                            }
                            for(int i=0;i<3;i++){
                                tmpface4[i][2]=face3[0][i];
                            }

                       }



                       
                           else if(rot=="B"){
                            for(int i=0;i<3;i++){
                                for(int j=0;j<3;j++){
                                    tmpface5[j][2-i]=face5[i][j];
                                }
                            }

                           
                                for(int i=2;i>=0;i--){
                                        tmpface0[0][i]=face1[i][2];
                                }
                            
                            for(int i=2;i>=0;i--){
                                        tmpface1[i][2]=face3[2][2-i];
                                }
                            for(int i=0;i<3;i++){
                                tmpface3[2][i]=face4[i][0];
                            }
                            for(int i=0;i<3;i++){
                                tmpface4[i][0]=face0[0][2-i];
                            }

                       }






                      else   if(rot=="U'"){
                            for(int i=0;i<3;i++){
                                for(int j=0;j<3;j++){
                                    tmpface0[2-j][i]=face0[i][j];
                                }
                            }
                            for(int j=0;j<3;j++){
                                tmpface1[0][j]=face2[0][j];
                            }
                            for(int j=0;j<3;j++){
                                tmpface5[0][j]=face1[0][j];
                            }
                            for(int j=0;j<3;j++){
                                tmpface4[0][j]=face5[0][j];
                            }
                            for(int j=0;j<3;j++){
                                tmpface2[0][j]=face4[0][j];
                            }
                       }
                       else if(rot=="D'"){
                            for(int i=0;i<3;i++){
                                for(int j=0;j<3;j++){
                                    tmpface3[2-j][i]=face3[i][j];
                                }
                            }

                            for(int j=0;j<3;j++){
                                tmpface2[2][j]=face1[2][j];
                            }
                            for(int j=0;j<3;j++){
                                tmpface1[2][j]=face5[2][j];
                            }
                            for(int j=0;j<3;j++){
                                tmpface5[2][j]=face4[2][j];
                            }
                            for(int j=0;j<3;j++){
                                tmpface4[2][j]=face2[2][j];
                            }
                       }


                       else if(rot=="R'"){
                              for(int i=0;i<3;i++){
                                for(int j=0;j<3;j++){
                                    tmpface1[2-j][i]=face1[i][j];
                                }
                            }

                
                           for(int i=0;i<3;i++){
                                tmpface2[i][2]=face0[i][2];
                            }
                           for(int i=0;i<3;i++){
                                tmpface0[i][2]=face5[2-i][0];
                            }
                            for(int i=0;i<3;i++){
                                tmpface5[2-i][0]=face3[i][2];
                            }
                            for(int i=0;i<3;i++){
                                tmpface3[i][2]=face2[i][2];
                            }

                           

                       }


                           else if(rot=="L'"){
                             for(int i=0;i<3;i++){
                                for(int j=0;j<3;j++){
                                    tmpface4[2-j][i]=face4[i][j];
                                }
                            }

                

                            for(int i=0;i<3;i++){
                                tmpface2[i][0]=face3[i][0];
                            }
                           for(int i=0;i<3;i++){
                                tmpface3[i][0]=face5[2-i][2];
                            }
                            for(int i=0;i<3;i++){
                                tmpface5[i][2]=face0[2-i][0];
                            }
                            for(int i=0;i<3;i++){
                                tmpface0[i][0]=face2[i][0];
                            }
                       }


                       
                           else if(rot=="F'"){
                              for(int i=0;i<3;i++){
                                for(int j=0;j<3;j++){
                                    tmpface2[2-j][i]=face2[i][j];
                                }
                            }

                           
                                for(int i=2;i>=0;i--){
                                        tmpface0[2][i]=face1[i][0];
                                }
                            
                            for(int i=2;i>=0;i--){
                                        tmpface1[2-i][0]=face3[0][i];
                                }
                            for(int i=0;i<3;i++){
                                tmpface3[0][i]=face4[i][2];
                            }
                            for(int i=0;i<3;i++){
                                tmpface4[2-i][2]=face0[2][i];
                            }

                       }



                       
                           else if(rot=="B'"){
                            for(int i=0;i<3;i++){
                                for(int j=0;j<3;j++){
                                    tmpface5[2-j][i]=face5[i][j];
                                }
                            }

                           
                                for(int i=2;i>=0;i--){
                                        tmpface0[0][2-i]=face4[i][0];
                                }
                            
                            for(int i=2;i>=0;i--){
                                        tmpface1[i][2]=face0[0][i];
                                }
                            for(int i=0;i<3;i++){
                                tmpface3[2][i]=face1[2-i][2];
                            }
                            for(int i=0;i<3;i++){
                                tmpface4[i][0]=face3[2][i];
                            }

                       }



                       else if(rot=="U2"){
                            for(int i=0;i<3;i++){
                                for(int j=0;j<3;j++){
                                    tmpface0[j][2-i]=face0[i][j];
                                }
                            }
                            for(int j=0;j<3;j++){
                                tmpface1[0][j]=face5[0][j];
                            }
                            for(int j=0;j<3;j++){
                                tmpface2[0][j]=face1[0][j];
                            }
                            for(int j=0;j<3;j++){
                                tmpface4[0][j]=face2[0][j];
                            }
                            for(int j=0;j<3;j++){
                                tmpface5[0][j]=face4[0][j];
                            }
                            
                            face0 = tmpface0;
                            face1 = tmpface1;
                            face2 = tmpface2;
                            face3 = tmpface3;
                            face4 = tmpface4;
                            face5 = tmpface5;

                            for(int i=0;i<3;i++){
                                for(int j=0;j<3;j++){
                                    tmpface0[j][2-i]=face0[i][j];
                                }
                            }
                            for(int j=0;j<3;j++){
                                tmpface1[0][j]=face5[0][j];
                            }
                            for(int j=0;j<3;j++){
                                tmpface2[0][j]=face1[0][j];
                            }
                            for(int j=0;j<3;j++){
                                tmpface4[0][j]=face2[0][j];
                            }
                            for(int j=0;j<3;j++){
                                tmpface5[0][j]=face4[0][j];
                            }
                            

                            
                       }
                       else if(rot=="D2"){
                                    for(int i=0;i<3;i++){
                                for(int j=0;j<3;j++){
                                    tmpface3[j][2-i]=face3[i][j];
                                }
                            }

                            for(int j=0;j<3;j++){
                                tmpface1[2][j]=face2[2][j];
                            }
                            for(int j=0;j<3;j++){
                                tmpface5[2][j]=face1[2][j];
                            }
                            for(int j=0;j<3;j++){
                                tmpface4[2][j]=face5[2][j];
                            }
                            for(int j=0;j<3;j++){
                                tmpface2[2][j]=face4[2][j];
                            }

                              face0 = tmpface0;
                            face1 = tmpface1;
                            face2 = tmpface2;
                            face3 = tmpface3;
                            face4 = tmpface4;
                            face5 = tmpface5;


                            for(int i=0;i<3;i++){
                                for(int j=0;j<3;j++){
                                    tmpface3[j][2-i]=face3[i][j];
                                }
                            }

                            for(int j=0;j<3;j++){
                                tmpface1[2][j]=face2[2][j];
                            }
                            for(int j=0;j<3;j++){
                                tmpface5[2][j]=face1[2][j];
                            }
                            for(int j=0;j<3;j++){
                                tmpface4[2][j]=face5[2][j];
                            }
                            for(int j=0;j<3;j++){
                                tmpface2[2][j]=face4[2][j];
                               }
                            }

                               else if(rot=="R2"){
                                    // Apply R rotation twice
                                    for(int i=0;i<3;i++){
                                        for(int j=0;j<3;j++){
                                            tmpface1[j][2-i]=face1[i][j];
                                        }
                                    }
                                    for(int i=0;i<3;i++){
                                        tmpface2[i][2]=face3[i][2];
                                    }
                                    for(int i=0;i<3;i++){
                                        tmpface3[i][2]=face5[2-i][0];
                                    }
                                    for(int i=0;i<3;i++){
                                        tmpface5[2-i][0]=face0[i][2];
                                    }
                                    for(int i=0;i<3;i++){
                                        tmpface0[i][2]=face2[i][2];
                                    }

                                    face0 = tmpface0;
                                    face1 = tmpface1;
                                    face2 = tmpface2;
                                    face3 = tmpface3;
                                    face4 = tmpface4;
                                    face5 = tmpface5;

                                    for(int i=0;i<3;i++){
                                        for(int j=0;j<3;j++){
                                            tmpface1[j][2-i]=face1[i][j];
                                        }
                                    }
                                    for(int i=0;i<3;i++){
                                        tmpface2[i][2]=face3[i][2];
                                    }
                                    for(int i=0;i<3;i++){
                                        tmpface3[i][2]=face5[2-i][0];
                                    }
                                    for(int i=0;i<3;i++){
                                        tmpface5[2-i][0]=face0[i][2];
                                    }
                                    for(int i=0;i<3;i++){
                                        tmpface0[i][2]=face2[i][2];
                                    }
                               }
                               else if(rot=="L2"){
                                    // Apply L rotation twice
                                    for(int i=0;i<3;i++){
                                        for(int j=0;j<3;j++){
                                            tmpface4[j][2-i]=face4[i][j];
                                        }
                                    }
                                    for(int i=0;i<3;i++){
                                        tmpface2[i][0]=face0[i][0];
                                    }
                                    for(int i=0;i<3;i++){
                                        tmpface0[i][0]=face5[2-i][2];
                                    }
                                    for(int i=0;i<3;i++){
                                        tmpface5[i][2]=face3[2-i][0];
                                    }
                                    for(int i=0;i<3;i++){
                                        tmpface3[i][0]=face2[i][0];
                                    }

                                    face0 = tmpface0;
                                    face1 = tmpface1;
                                    face2 = tmpface2;
                                    face3 = tmpface3;
                                    face4 = tmpface4;
                                    face5 = tmpface5;

                                    for(int i=0;i<3;i++){
                                        for(int j=0;j<3;j++){
                                            tmpface4[j][2-i]=face4[i][j];
                                        }
                                    }
                                    for(int i=0;i<3;i++){
                                        tmpface2[i][0]=face0[i][0];
                                    }
                                    for(int i=0;i<3;i++){
                                        tmpface0[i][0]=face5[2-i][2];
                                    }
                                    for(int i=0;i<3;i++){
                                        tmpface5[i][2]=face3[2-i][0];
                                    }
                                    for(int i=0;i<3;i++){
                                        tmpface3[i][0]=face2[i][0];
                                    }
                               }
                               else if(rot=="F2"){
                                    // Apply F rotation twice
                                    for(int i=0;i<3;i++){
                                        for(int j=0;j<3;j++){
                                            tmpface2[j][2-i]=face2[i][j];
                                        }
                                    }
                                    for(int i=2;i>=0;i--){
                                        tmpface0[2][2-i]=face4[i][2];
                                    }
                                    for(int i=2;i>=0;i--){
                                        tmpface1[i][0]=face0[2][i];
                                    }
                                    for(int i=0;i<3;i++){
                                        tmpface3[0][i]=face1[2-i][0];
                                    }
                                    for(int i=0;i<3;i++){
                                        tmpface4[i][2]=face3[0][i];
                                    }

                                    face0 = tmpface0;
                                    face1 = tmpface1;
                                    face2 = tmpface2;
                                    face3 = tmpface3;
                                    face4 = tmpface4;
                                    face5 = tmpface5;

                                    for(int i=0;i<3;i++){
                                        for(int j=0;j<3;j++){
                                            tmpface2[j][2-i]=face2[i][j];
                                        }
                                    }
                                    for(int i=2;i>=0;i--){
                                        tmpface0[2][2-i]=face4[i][2];
                                    }
                                    for(int i=2;i>=0;i--){
                                        tmpface1[i][0]=face0[2][i];
                                    }
                                    for(int i=0;i<3;i++){
                                        tmpface3[0][i]=face1[2-i][0];
                                    }
                                    for(int i=0;i<3;i++){
                                        tmpface4[i][2]=face3[0][i];
                                    }
                               }
                               else if(rot=="B2"){
                                    // Apply B rotation twice
                                    for(int i=0;i<3;i++){
                                        for(int j=0;j<3;j++){
                                            tmpface5[j][2-i]=face5[i][j];
                                        }
                                    }
                                    for(int i=2;i>=0;i--){
                                        tmpface0[0][i]=face1[i][2];
                                    }
                                    for(int i=2;i>=0;i--){
                                        tmpface1[i][2]=face3[2][2-i];
                                    }
                                    for(int i=0;i<3;i++){
                                        tmpface3[2][i]=face4[i][0];
                                    }
                                    for(int i=0;i<3;i++){
                                        tmpface4[i][0]=face0[0][2-i];
                                    }

                                    face0 = tmpface0;
                                    face1 = tmpface1;
                                    face2 = tmpface2;
                                    face3 = tmpface3;
                                    face4 = tmpface4;
                                    face5 = tmpface5;

                                    for(int i=0;i<3;i++){
                                        for(int j=0;j<3;j++){
                                            tmpface5[j][2-i]=face5[i][j];
                                        }
                                    }
                                    for(int i=2;i>=0;i--){
                                        tmpface0[0][i]=face1[i][2];
                                    }
                                    for(int i=2;i>=0;i--){
                                        tmpface1[i][2]=face3[2][2-i];
                                    }
                                    for(int i=0;i<3;i++){
                                        tmpface3[2][i]=face4[i][0];
                                    }
                                    for(int i=0;i<3;i++){
                                        tmpface4[i][0]=face0[0][2-i];
                                    }
                               }
                              



                       



           string str="";
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    str+=tmpface0[i][j];
                }
            }
             for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    str+=tmpface1[i][j];
                }
            }
             for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    str+=tmpface2[i][j];
                }
            }
             for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    str+=tmpface3[i][j];
                }
            }
             for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    str+=tmpface4[i][j];
                }
            }
             for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    str+=tmpface5[i][j];
                }
            }


            scramble=str;
}


void handleRotation(string rot){
          handleRotationAndUpdate(rot,scramble);
           //    FRONT LAYER
       piece_to_pos.clear();
       pos_to_piece.clear();
       piece_to_pos[{scramble[6],scramble[18],scramble[38]}]=1;
       pos_to_piece[1]={scramble[6],scramble[18],scramble[38]};
       piece_to_pos[{scramble[19],scramble[7]}]=2;
       pos_to_piece[2]={scramble[19],scramble[7]};
       piece_to_pos[{scramble[8],scramble[20],scramble[9]}]=3;
       pos_to_piece[3]={scramble[8],scramble[20],scramble[9]};

       piece_to_pos[{scramble[21],scramble[41]}]=4;
       pos_to_piece[4]={scramble[21],scramble[41]};
       piece_to_pos[{scramble[23],scramble[12]}]=6;
       pos_to_piece[6]={scramble[23],scramble[12]};

       piece_to_pos[{scramble[24],scramble[44],scramble[27]}]=7;
       pos_to_piece[7]={scramble[24],scramble[44],scramble[27]};
       piece_to_pos[{scramble[25],scramble[28]}]=8;
       pos_to_piece[8]={scramble[25],scramble[28]};
       piece_to_pos[{scramble[26],scramble[15],scramble[29]}]=9;
       pos_to_piece[9]={scramble[26],scramble[15],scramble[29]};


    //    MIDDLE LAYER

       piece_to_pos[{scramble[3],scramble[37]}]=10;
       pos_to_piece[10]={scramble[3],scramble[37]};
       piece_to_pos[{scramble[5],scramble[10]}]=12;
       pos_to_piece[12]={scramble[5],scramble[10]};
      

       piece_to_pos[{scramble[43],scramble[30]}]=16;
       pos_to_piece[16]={scramble[43],scramble[30]};
       piece_to_pos[{scramble[16],scramble[32]}]=18;
       pos_to_piece[18]={scramble[16],scramble[32]};



    //   BACK LAYER 


     piece_to_pos[{scramble[0],scramble[36],scramble[47]}]=19;
       pos_to_piece[19]={scramble[0],scramble[36],scramble[47]};
       piece_to_pos[{scramble[1],scramble[46]}]=20;
       pos_to_piece[20]={scramble[1],scramble[46]};
       piece_to_pos[{scramble[2],scramble[11],scramble[45]}]=21;
       pos_to_piece[21]={scramble[2],scramble[11],scramble[45]};

       piece_to_pos[{scramble[39],scramble[50]}]=22;
       pos_to_piece[22]={scramble[39],scramble[50]};
       piece_to_pos[{scramble[14],scramble[48]}]=24;
       pos_to_piece[24]={scramble[14],scramble[48]};

       piece_to_pos[{scramble[42],scramble[53],scramble[33]}]=25;
       pos_to_piece[25]={scramble[42],scramble[53],scramble[33]};
       piece_to_pos[{scramble[52],scramble[34]}]=26;
       pos_to_piece[26]={scramble[52],scramble[34]};
       piece_to_pos[{scramble[17],scramble[51],scramble[35]}]=27;
       pos_to_piece[27]={scramble[17],scramble[51],scramble[35]};

}

void upper_Layer_Cross(){




       

     while(1){
      // cerr << "DBG: entering loop step" << endl;

        
        // cout<<ans.back()<<" ";
    // UPPER FRONT PIECE
      if(piece_to_pos.find({'U','F'})!=piece_to_pos.end()){
             Pos pos=indexToPos[piece_to_pos[{'U','F'}]];
                //  cout<<pos.x<<" "<<pos.y<<" "<<pos.z<<endl;
             // UPPER LAYER 
             if(pos.y==1){
                  // FRONT
                   if(pos.z==1){
                        ans.push_back("F2");
                        handleRotation("F2");
                   }
                   // BACK
                   else if(pos.z==-1){
                          ans.push_back("B2");
                        handleRotation("B2");
                   }
                   // RIGHT 
                   else if(pos.x==1){
                      ans.push_back("R2");
                        handleRotation("R2");
                   }
                   // LEFT
                   else {
                      ans.push_back("L2");
                        handleRotation("L2");
                   }
             }
             // MIDDLE LAYER
             else if(pos.y==0){

                // FRONT - RIGHT
                  if(pos.x==1 && pos.z==1){
                       vector<char>cubie1=pos_to_piece[12];
                        vector<char>cubie2=pos_to_piece[2];
                    
                        if(cubie1[0]=='U' && cubie1[1]=='R'){
                                 if(cubie2[0]=='F' && cubie2[1]=='U'){
                                        ans.push_back("R'");
                        handleRotation("R'");
                        ans.push_back("D'");
                        handleRotation("D'");
                        ans.push_back("R");
                        handleRotation("R");
                                 }
                                 else{
                                    ans.push_back("F");
                        handleRotation("F");
                                 }
                        }
                        else{
                            ans.push_back("R'");
                        handleRotation("R'");
                        }

                  }

                //   FRONT - LEFT
                  else if(pos.x==-1 && pos.z==1){
                             vector<char>cubie1=pos_to_piece[10];
                        vector<char>cubie2=pos_to_piece[2];
                      
                        if(cubie1[0]=='U' && cubie1[1]=='L'){
                                 if(cubie2[0]=='F' && cubie2[1]=='U'){
                                    
                                        ans.push_back("L");
                        handleRotation("L");
                        ans.push_back("D");
                        handleRotation("D");
                        ans.push_back("L'");
                        handleRotation("L'");
                                 }
                                 else{
                                    ans.push_back("F'");
                        handleRotation("F'");
                                 }
                        }
                        else{
                            ans.push_back("L");
                        handleRotation("L");
    







    

    
                        }
                  }

                //   RIGHT - BACK
                  else if(pos.x==1 && pos.z==-1){
                          vector<char>cubie1=pos_to_piece[12];
                        vector<char>cubie2=pos_to_piece[20];

                        if(cubie1[0]=='U' && cubie1[1]=='R'){
                                 if(cubie2[0]=='U' && cubie2[1]=='B'){
                                        ans.push_back("R");
                        handleRotation("R");
                        ans.push_back("D'");
                        handleRotation("D'");
                        ans.push_back("R'");
                        handleRotation("R'");
                                 }
                                 else{
                                    ans.push_back("B'");
                        handleRotation("B'");
                                 }
                        }
                        else{
                            ans.push_back("R");
                        handleRotation("R");
                        }
                  }

                //   LEFT - BACK
                  else{
                      vector<char>cubie1=pos_to_piece[10];
                        vector<char>cubie2=pos_to_piece[20];

                        if(cubie1[0]=='U' && cubie1[1]=='L'){
                                 if(cubie2[0]=='U' && cubie2[1]=='B'){
                                        ans.push_back("L'");
                        handleRotation("L'");
                        ans.push_back("D");
                        handleRotation("D");
                        ans.push_back("L");
                        handleRotation("L");
                                 }
                                 else{
                                    ans.push_back("B");
                        handleRotation("B");
                                 }
                        }
                        else{
                            ans.push_back("L'");
                        handleRotation("L'");
                        }
                  }
             }
             // BOTTOM LAYER
             else{
                       // FRONT
                   if(pos.z==1){
                       vector<char>cubie=pos_to_piece[8];
                       if(cubie[0]=='F' && cubie[1]=='U'){
                               ans.push_back("F2");
                        handleRotation("F2");
                       }
                       else{
                      ans.push_back("D'");
                        handleRotation("D'");
                        ans.push_back("L'");
                        handleRotation("L'");
                         ans.push_back("F");
                        handleRotation("F");
                         ans.push_back("L");
                        handleRotation("L");
                       }
                        
                   }
                   // BACK
                   else if(pos.z==-1){
                          ans.push_back("D2");
                        handleRotation("D2");
                         vector<char>cubie=pos_to_piece[8];
                       if(cubie[0]=='F' && cubie[1]=='U'){
                               ans.push_back("F2");
                        handleRotation("F2");
                       }
                       else{
                      ans.push_back("D'");
                        handleRotation("D'");
                        ans.push_back("L'");
                        handleRotation("L'");
                         ans.push_back("F");
                        handleRotation("F");
                         ans.push_back("L");
                        handleRotation("L");
                       }

                   }
                   // RIGHT 
                   else if(pos.x==1){
                      ans.push_back("D'");
                        handleRotation("D'");
                         vector<char>cubie=pos_to_piece[8];
                       if(cubie[0]=='F' && cubie[1]=='U'){
                               ans.push_back("F2");
                        handleRotation("F2");
                       }
                       else{
                      ans.push_back("D'");
                        handleRotation("D'");
                        ans.push_back("L'");
                        handleRotation("L'");
                         ans.push_back("F");
                        handleRotation("F");
                         ans.push_back("L");
                        handleRotation("L");
                       }

                   }
                   // LEFT
                   else {
                      ans.push_back("D");
                        handleRotation("D");
                         vector<char>cubie=pos_to_piece[8];
                       if(cubie[0]=='F' && cubie[1]=='U'){
                               ans.push_back("F2");
                        handleRotation("F2");
                       }
                       else{
                      ans.push_back("D'");
                        handleRotation("D'");
                        ans.push_back("L'");
                        handleRotation("L'");
                         ans.push_back("F");
                        handleRotation("F");
                         ans.push_back("L");
                        handleRotation("L");
                       }
                   }
             }
      }




      else if(piece_to_pos.find({'F','U'})!=piece_to_pos.end()){
                     Pos pos=indexToPos[piece_to_pos[{'F','U'}]];
                    //  cout<<pos.x<<" "<<pos.y<<" "<<pos.z<<endl;
             // UPPER LAYER 
             if(pos.y==1){
                  // FRONT
                  // --- NOTHING TO DO ---
                  if(pos.z==1){
                    break;
                  }

                  // BACK 
                 else  if(pos.z==-1){
                          ans.push_back("B2");
                        handleRotation("B2");
                   }
                   // RIGHT 
                   else if(pos.x==1){
                      ans.push_back("R2");
                        handleRotation("R2");
                   }
                   // LEFT
                   else {
                      ans.push_back("L2");
                        handleRotation("L2");
                   }
             }
             // MIDDLE LAYER
             else if(pos.y==0){

                // FRONT - RIGHT
                  if(pos.x==1 && pos.z==1){
                       vector<char>cubie1=pos_to_piece[12];
                        vector<char>cubie2=pos_to_piece[2];

                        if(cubie1[0]=='U' && cubie1[1]=='R'){
                                 if(cubie2[0]=='F' && cubie2[1]=='U'){
                                        ans.push_back("R'");
                        handleRotation("R'");
                        ans.push_back("D'");
                        handleRotation("D'");
                        ans.push_back("R");
                        handleRotation("R");
                                 }
                                 else{
                                    ans.push_back("F");
                        handleRotation("F");
                                 }
                        }
                        else{
                            ans.push_back("R'");
                        handleRotation("R'");
                        }

                  }

                //   FRONT - LEFT
                  else if(pos.x==-1 && pos.z==1){
                             vector<char>cubie1=pos_to_piece[10];
                        vector<char>cubie2=pos_to_piece[2];

                        if(cubie1[0]=='U' && cubie1[1]=='L'){
                                 if(cubie2[0]=='F' && cubie2[1]=='U'){
                                        ans.push_back("L");
                        handleRotation("L");
                        ans.push_back("D");
                        handleRotation("D");
                        ans.push_back("L'");
                        handleRotation("L'");
                                 }
                                 else{
                                    ans.push_back("F'");
                        handleRotation("F'");
                                 }
                        }
                        else{
                            ans.push_back("L");
                        handleRotation("L");
                        }
                  }

                //   RIGHT - BACK
                  else if(pos.x==1 && pos.z==-1){
                          vector<char>cubie1=pos_to_piece[12];
                        vector<char>cubie2=pos_to_piece[20];

                        if(cubie1[0]=='U' && cubie1[1]=='R'){
                                 if(cubie2[0]=='U' && cubie2[1]=='B'){
                                        ans.push_back("R");
                        handleRotation("R");
                        ans.push_back("D'");
                        handleRotation("D'");
                        ans.push_back("R'");
                        handleRotation("R'");
                                 }
                                 else{
                                    ans.push_back("B'");
                        handleRotation("B'");
                                 }
                        }
                        else{
                            ans.push_back("R");
                        handleRotation("R");
                        }
                  }

                //   LEFT - BACK
                  else{
                      vector<char>cubie1=pos_to_piece[10];
                        vector<char>cubie2=pos_to_piece[20];

                        if(cubie1[0]=='U' && cubie1[1]=='L'){
                                 if(cubie2[0]=='U' && cubie2[1]=='B'){
                                        ans.push_back("L'");
                        handleRotation("L'");
                        ans.push_back("D");
                        handleRotation("D");
                        ans.push_back("L");
                        handleRotation("L");
                                 }
                                 else{
                                    ans.push_back("B");
                        handleRotation("B");
                                 }
                        }
                        else{
                            ans.push_back("L'");
                        handleRotation("L'");
                        }
                  }
             }
             // BOTTOM LAYER
             else{
                       // FRONT
                   if(pos.z==1){
                       vector<char>cubie=pos_to_piece[8];
                       if(cubie[0]=='F' && cubie[1]=='U'){
                               ans.push_back("F2");
                        handleRotation("F2");
                       }
                       else{
                      ans.push_back("D'");
                        handleRotation("D'");
                        ans.push_back("L'");
                        handleRotation("L'");
                         ans.push_back("F");
                        handleRotation("F");
                         ans.push_back("L");
                        handleRotation("L");
                       }
                        
                   }
                   // BACK
                   else if(pos.z==-1){
                          ans.push_back("D2");
                        handleRotation("D2");
                         vector<char>cubie=pos_to_piece[8];
                       if(cubie[0]=='F' && cubie[1]=='U'){
                               ans.push_back("F2");
                        handleRotation("F2");
                       }
                       else{
                      ans.push_back("D'");
                        handleRotation("D'");
                        ans.push_back("L'");
                        handleRotation("L'");
                         ans.push_back("F");
                        handleRotation("F");
                         ans.push_back("L");
                        handleRotation("L");
                       }

                   }
                   // RIGHT 
                   else if(pos.x==1){
                      ans.push_back("D'");
                        handleRotation("D'");
                         vector<char>cubie=pos_to_piece[8];
                       if(cubie[0]=='F' && cubie[1]=='U'){
                               ans.push_back("F2");
                        handleRotation("F2");
                       }
                       else{
                      ans.push_back("D'");
                        handleRotation("D'");
                        ans.push_back("L'");
                        handleRotation("L'");
                         ans.push_back("F");
                        handleRotation("F");
                         ans.push_back("L");
                        handleRotation("L");
                       }

                   }
                   // LEFT
                   else {
                      ans.push_back("D");
                        handleRotation("D");
                         vector<char>cubie=pos_to_piece[8];
                       if(cubie[0]=='F' && cubie[1]=='U'){
                               ans.push_back("F2");
                        handleRotation("F2");
                       }
                       else{
                      ans.push_back("D'");
                        handleRotation("D'");
                        ans.push_back("L'");
                        handleRotation("L'");
                         ans.push_back("F");
                        handleRotation("F");
                         ans.push_back("L");
                        handleRotation("L");
                       }
                   }
             }
      }
    }






     while(1){
// cerr << "DBG: entering loop step" << endl;


       // UPPER RIGHT PIECE
      if(piece_to_pos.find({'U','R'})!=piece_to_pos.end()){
             Pos pos=indexToPos[piece_to_pos[{'U','R'}]];

            //  cout<<pos.x<<" "<<pos.y<<" "<<pos.z<<endl;
             // UPPER LAYER 
             if(pos.y==1){
                  // FRONT
                   if(pos.z==1){
                        ans.push_back("F2");
                        handleRotation("F2");
                   }
                   // BACK
                   else if(pos.z==-1){
                          ans.push_back("B2");
                        handleRotation("B2");
                   }
                   // RIGHT 
                   // NOTHING TO DO
                   if(pos.x==1){
                          break;
                   }

                   // LEFT
                   else {

                     
                      ans.push_back("L2");
                        handleRotation("L2");
                   }
             }
             // MIDDLE LAYER
             else if(pos.y==0){

                // FRONT - RIGHT
                  if(pos.x==1 && pos.z==1){
                       vector<char>cubie1=pos_to_piece[12];
                        vector<char>cubie2=pos_to_piece[2];

                        if(cubie1[0]=='U' && cubie1[1]=='R'){
                                 if(cubie2[0]=='F' && cubie2[1]=='U'){
                                        ans.push_back("R'");
                        handleRotation("R'");
                        ans.push_back("D'");
                        handleRotation("D'");
                        ans.push_back("R");
                        handleRotation("R");
                                 }
                                 else{
                                    ans.push_back("F");
                        handleRotation("F");
                                 }
                        }
                        else{
                            ans.push_back("R'");
                        handleRotation("R'");
                        }

                  }

                //   FRONT - LEFT
                  else if(pos.x==-1 && pos.z==1){
                             vector<char>cubie1=pos_to_piece[10];
                        vector<char>cubie2=pos_to_piece[2];

                        if(cubie1[0]=='U' && cubie1[1]=='L'){
                                 if(cubie2[0]=='F' && cubie2[1]=='U'){
                                        ans.push_back("L");
                        handleRotation("L");
                        ans.push_back("D");
                        handleRotation("D");
                        ans.push_back("L'");
                        handleRotation("L'");
                                 }
                                 else{
                                    ans.push_back("F'");
                        handleRotation("F'");
                                 }
                        }
                        else{
                            ans.push_back("L");
                        handleRotation("L");
                        }
                  }

                //   RIGHT - BACK
                  else if(pos.x==1 && pos.z==-1){
                          vector<char>cubie1=pos_to_piece[12];
                        vector<char>cubie2=pos_to_piece[20];

                        if(cubie1[0]=='U' && cubie1[1]=='R'){
                                 if(cubie2[0]=='U' && cubie2[1]=='B'){
                                        ans.push_back("R");
                        handleRotation("R");
                        ans.push_back("D'");
                        handleRotation("D'");
                        ans.push_back("R'");
                        handleRotation("R'");
                                 }
                                 else{
                                    ans.push_back("B'");
                        handleRotation("B'");
                                 }
                        }
                        else{
                            ans.push_back("R");
                        handleRotation("R");
                        }
                  }

                //   LEFT - BACK
                  else{
                      vector<char>cubie1=pos_to_piece[10];
                        vector<char>cubie2=pos_to_piece[20];

                        if(cubie1[0]=='U' && cubie1[1]=='L'){
                                 if(cubie2[0]=='U' && cubie2[1]=='B'){
                                        ans.push_back("L'");
                        handleRotation("L'");
                        ans.push_back("D");
                        handleRotation("D");
                        ans.push_back("L");
                        handleRotation("L");
                                 }
                                 else{
                                    ans.push_back("B");
                        handleRotation("B");
                                 }
                        }
                        else{
                            ans.push_back("L'");
                        handleRotation("L'");
                        }
                  }
             }
             // BOTTOM LAYER
             else{
                       // FRONT
                   if(pos.z==1){

                      ans.push_back("D");
                        handleRotation("D");
                      
                       vector<char>cubie=pos_to_piece[18];
                       if(cubie[0]=='R' && cubie[1]=='U'){
                               ans.push_back("R2");
                        handleRotation("R2");
                       }
                       else{
                      ans.push_back("D'");
                        handleRotation("D'");
                         ans.push_back("F'");
                        handleRotation("F'");
                         ans.push_back("R");
                        handleRotation("R");
                         ans.push_back("F");
                        handleRotation("F");
                       }
                        
                   }
                   // BACK
                   else if(pos.z==-1){
                          ans.push_back("D'");
                        handleRotation("D'");
                         vector<char>cubie=pos_to_piece[18];
                       if(cubie[0]=='R' && cubie[1]=='U'){
                               ans.push_back("R2");
                        handleRotation("R2");
                       }
                       else{
                      ans.push_back("D'");
                        handleRotation("D'");
                         ans.push_back("F'");
                        handleRotation("F'");
                         ans.push_back("R");
                        handleRotation("R");
                         ans.push_back("F");
                        handleRotation("F");
                       }

                   }
                   // RIGHT 
                   else if(pos.x==1){
                      vector<char>cubie=pos_to_piece[18];
                       if(cubie[0]=='R' && cubie[1]=='U'){
                               ans.push_back("R2");
                        handleRotation("R2");
                       }
                       else{
                      ans.push_back("D'");
                        handleRotation("D'");
                         ans.push_back("F'");
                        handleRotation("F'");
                         ans.push_back("R");
                        handleRotation("R");
                         ans.push_back("F");
                        handleRotation("F");
                       }

                   }
                   // LEFT
                   else {
                      ans.push_back("D2");
                        handleRotation("D2");
                         vector<char>cubie=pos_to_piece[18];
                       if(cubie[0]=='R' && cubie[1]=='U'){
                               ans.push_back("R2");
                        handleRotation("R2");
                       }
                       else{
                      ans.push_back("D'");
                        handleRotation("D'");
                         ans.push_back("F'");
                        handleRotation("F'");
                         ans.push_back("R");
                        handleRotation("R");
                         ans.push_back("F");
                        handleRotation("F");
                       }
                   }
             }
      }




      else if(piece_to_pos.find({'R','U'})!=piece_to_pos.end()){
                     Pos pos=indexToPos[piece_to_pos[{'R','U'}]];
             // UPPER LAYER 
             if(pos.y==1){
                  // FRONT
                  if(pos.z==1){
                          ans.push_back("F2");
                        handleRotation("F2");
                   }

                  // BACK 
                 else  if(pos.z==-1){
                          ans.push_back("B2");
                        handleRotation("B2");
                   }
                   // RIGHT 
                   else if(pos.x==1){
                      ans.push_back("R2");
                        handleRotation("R2");
                   }
                   // LEFT
                   else {
                      ans.push_back("L2");
                        handleRotation("L2");
                   }
             }
             // MIDDLE LAYER
             else if(pos.y==0){

                // FRONT - RIGHT
                  if(pos.x==1 && pos.z==1){
                       vector<char>cubie1=pos_to_piece[12];
                        vector<char>cubie2=pos_to_piece[2];

                        if(cubie1[0]=='U' && cubie1[1]=='R'){
                                 if(cubie2[0]=='F' && cubie2[1]=='U'){
                                        ans.push_back("R'");
                        handleRotation("R'");
                        ans.push_back("D'");
                        handleRotation("D'");
                        ans.push_back("R");
                        handleRotation("R");
                                 }
                                 else{
                                    ans.push_back("F");
                        handleRotation("F");
                                 }
                        }
                        else{
                            ans.push_back("R'");
                        handleRotation("R'");
                        }

                  }

                //   FRONT - LEFT
                  else if(pos.x==-1 && pos.z==1){
                             vector<char>cubie1=pos_to_piece[10];
                        vector<char>cubie2=pos_to_piece[2];

                        if(cubie1[0]=='U' && cubie1[1]=='L'){
                                 if(cubie2[0]=='F' && cubie2[1]=='U'){
                                        ans.push_back("L");
                        handleRotation("L");
                        ans.push_back("D");
                        handleRotation("D");
                        ans.push_back("L'");
                        handleRotation("L'");
                                 }
                                 else{
                                    ans.push_back("F'");
                        handleRotation("F'");
                                 }
                        }
                        else{
                            ans.push_back("L");
                        handleRotation("L");
                        }
                  }

                //   RIGHT - BACK
                  else if(pos.x==1 && pos.z==-1){
                          vector<char>cubie1=pos_to_piece[12];
                        vector<char>cubie2=pos_to_piece[20];

                        if(cubie1[0]=='U' && cubie1[1]=='R'){
                                 if(cubie2[0]=='U' && cubie2[1]=='B'){
                                        ans.push_back("R");
                        handleRotation("R");
                        ans.push_back("D'");
                        handleRotation("D'");
                        ans.push_back("R'");
                        handleRotation("R'");
                                 }
                                 else{
                                    ans.push_back("B'");
                        handleRotation("B'");
                                 }
                        }
                        else{
                            ans.push_back("R");
                        handleRotation("R");
                        }
                  }

                //   LEFT - BACK
                  else{
                      vector<char>cubie1=pos_to_piece[10];
                        vector<char>cubie2=pos_to_piece[20];

                        if(cubie1[0]=='U' && cubie1[1]=='L'){
                                 if(cubie2[0]=='U' && cubie2[1]=='B'){
                                        ans.push_back("L'");
                        handleRotation("L'");
                        ans.push_back("D");
                        handleRotation("D");
                        ans.push_back("L");
                        handleRotation("L");
                                 }
                                 else{
                                    ans.push_back("B");
                        handleRotation("B");
                                 }
                        }
                        else{
                            ans.push_back("L'");
                        handleRotation("L'");
                        }
                  }
             }
             // BOTTOM LAYER
             else{    
                     // FRONT
                   if(pos.z==1){

                      ans.push_back("D");
                        handleRotation("D");
                      
                       vector<char>cubie=pos_to_piece[18];
                       if(cubie[0]=='R' && cubie[1]=='U'){
                               ans.push_back("R2");
                        handleRotation("R2");
                       }
                       else{
                      ans.push_back("D'");
                        handleRotation("D'");
                         ans.push_back("F'");
                        handleRotation("F'");
                         ans.push_back("R");
                        handleRotation("R");
                         ans.push_back("F");
                        handleRotation("F");
                       }
                        
                   }
                   // BACK
                   else if(pos.z==-1){
                          ans.push_back("D'");
                        handleRotation("D'");
                         vector<char>cubie=pos_to_piece[18];
                       if(cubie[0]=='R' && cubie[1]=='U'){
                               ans.push_back("R2");
                        handleRotation("R2");
                       }
                       else{
                      ans.push_back("D'");
                        handleRotation("D'");
                         ans.push_back("F'");
                        handleRotation("F'");
                         ans.push_back("R");
                        handleRotation("R");
                         ans.push_back("F");
                        handleRotation("F");
                       }

                   }
                   // RIGHT 
                   else if(pos.x==1){
                      vector<char>cubie=pos_to_piece[18];
                       if(cubie[0]=='R' && cubie[1]=='U'){
                               ans.push_back("R2");
                        handleRotation("R2");
                       }
                       else{
                      ans.push_back("D'");
                        handleRotation("D'");
                         ans.push_back("F'");
                        handleRotation("F'");
                         ans.push_back("R");
                        handleRotation("R");
                         ans.push_back("F");
                        handleRotation("F");
                       }

                   }
                   // LEFT
                   else {
                      ans.push_back("D2");
                        handleRotation("D2");
                         vector<char>cubie=pos_to_piece[18];
                       if(cubie[0]=='R' && cubie[1]=='U'){
                               ans.push_back("R2");
                        handleRotation("R2");
                       }
                       else{
                      ans.push_back("D'");
                        handleRotation("D'");
                         ans.push_back("F'");
                        handleRotation("F'");
                         ans.push_back("R");
                        handleRotation("R");
                         ans.push_back("F");
                        handleRotation("F");
                       }
                   }
             }
      }

    }









   
   
      while(1){
       
      // cerr << "DBG: entering loop step" << endl;

      
       // UPPER BACK PIECE
      if(piece_to_pos.find({'U','B'})!=piece_to_pos.end()){
             Pos pos=indexToPos[piece_to_pos[{'U','B'}]];
             // UPPER LAYER 
            //  cout<<pos.x<<" "<<pos.y<<" "<<pos.z<<" "<<cnt<<endl;
             if(pos.y==1){
                  // FRONT
                   if(pos.z==1){
                        ans.push_back("F2");
                        handleRotation("F2");
                   }
                   // BACK
                   // NOTHING TO DO
                   if(pos.z==-1){
                        break;
                   }
                   // RIGHT 
                    else if(pos.x==1) {

                     
                      ans.push_back("R2");
                        handleRotation("R2");
                   }
                   

                   // LEFT
                   else {

                     
                      ans.push_back("L2");
                        handleRotation("L2");
                   }
             }
             // MIDDLE LAYER
             else if(pos.y==0){

                // FRONT - RIGHT
                  if(pos.x==1 && pos.z==1){
                       vector<char>cubie1=pos_to_piece[12];
                        vector<char>cubie2=pos_to_piece[2];
                   
                        if(cubie1[0]=='U' && cubie1[1]=='R'){
                                 if(cubie2[0]=='F' && cubie2[1]=='U'){
                                        ans.push_back("R'");
                        handleRotation("R'");
                        ans.push_back("D'");
                        handleRotation("D'");
                        ans.push_back("R");
                        handleRotation("R");
                                 }
                                 else{
                                    ans.push_back("F");
                        handleRotation("F");
                                 }
                        }
                        else{
                            ans.push_back("R'");
                        handleRotation("R'");
                        }

                  }

                //   FRONT - LEFT
                  else if(pos.x==-1 && pos.z==1){
                             vector<char>cubie1=pos_to_piece[10];
                        vector<char>cubie2=pos_to_piece[2];

                        if(cubie1[0]=='U' && cubie1[1]=='L'){
                                 if(cubie2[0]=='F' && cubie2[1]=='U'){
                                        ans.push_back("L");
                        handleRotation("L");
                        ans.push_back("D");
                        handleRotation("D");
                        ans.push_back("L'");
                        handleRotation("L'");
                                 }
                                 else{
                                    ans.push_back("F'");
                        handleRotation("F'");
                                 }
                        }
                        else{
                            ans.push_back("L");
                        handleRotation("L");
                        }
                  }

                //   RIGHT - BACK
                  else if(pos.x==1 && pos.z==-1){
                          vector<char>cubie1=pos_to_piece[12];
                        vector<char>cubie2=pos_to_piece[20];

                        if(cubie1[0]=='U' && cubie1[1]=='R'){
                                 if(cubie2[0]=='U' && cubie2[1]=='B'){
                                        ans.push_back("R");
                        handleRotation("R");
                        ans.push_back("D'");
                        handleRotation("D'");
                        ans.push_back("R'");
                        handleRotation("R'");
                                 }
                                 else{

                            
                                    ans.push_back("B'");
                        handleRotation("B'");
                                 }
                        }
                        else{
                            ans.push_back("R");
                        handleRotation("R");
                        }
                  }

                //   LEFT - BACK
                  else{
                      vector<char>cubie1=pos_to_piece[10];
                        vector<char>cubie2=pos_to_piece[20];

                        if(cubie1[0]=='U' && cubie1[1]=='L'){
                                 if(cubie2[0]=='U' && cubie2[1]=='B'){
                                        ans.push_back("L'");
                        handleRotation("L'");
                        ans.push_back("D");
                        handleRotation("D");
                        ans.push_back("L");
                        handleRotation("L");
                                 }
                                 else{
                                    ans.push_back("B");
                        handleRotation("B");
                                 }
                        }
                        else{
                            ans.push_back("L'");
                        handleRotation("L'");
                        }
                  }
             }
             // BOTTOM LAYER
             else{
                       // FRONT
                   if(pos.z==1){

                         ans.push_back("D2");
                        handleRotation("D2");


                      
                       vector<char>cubie=pos_to_piece[26];
                       if(cubie[0]=='B' && cubie[1]=='U'){
                               ans.push_back("B2");
                        handleRotation("B2");
                       }
                       else{
                      ans.push_back("D'");
                        handleRotation("D'");
                         ans.push_back("R'");
                        handleRotation("R'");
                         ans.push_back("B");
                        handleRotation("B");
                         ans.push_back("R");
                        handleRotation("R");
                       }
                        
                   }
                   // BACK
                   else if(pos.z==-1){
                          vector<char>cubie=pos_to_piece[26];
                       if(cubie[0]=='B' && cubie[1]=='U'){
                               ans.push_back("B2");
                        handleRotation("B2");
                       }
                       else{
                      ans.push_back("D'");
                        handleRotation("D'");
                         ans.push_back("R'");
                        handleRotation("R'");
                         ans.push_back("B");
                        handleRotation("B");
                         ans.push_back("R");
                        handleRotation("R");
                       }

                   }
                   // RIGHT 
                   if(pos.x==1){

                      ans.push_back("D");
                      handleRotation("D");    
                    vector<char>cubie=pos_to_piece[26];
                       if(cubie[0]=='B' && cubie[1]=='U'){
                               ans.push_back("B2");
                        handleRotation("B2");
                       }
                       else{
                      ans.push_back("D'");
                        handleRotation("D'");
                         ans.push_back("R'");
                        handleRotation("R'");
                         ans.push_back("B");
                        handleRotation("B");
                         ans.push_back("R");
                        handleRotation("R");
                       }

                   }
                   // LEFT
                   else {
                      ans.push_back("D'");
                        handleRotation("D'");
                         vector<char>cubie=pos_to_piece[26];
                       if(cubie[0]=='B' && cubie[1]=='U'){
                               ans.push_back("B2");
                        handleRotation("B2");
                       }
                       else{
                      ans.push_back("D'");
                        handleRotation("D'");
                         ans.push_back("R'");
                        handleRotation("R'");
                         ans.push_back("B");
                        handleRotation("B");
                         ans.push_back("R");
                        handleRotation("R");
                       }
                   }
             }
      }




      else if(piece_to_pos.find({'B','U'})!=piece_to_pos.end()){
                     Pos pos=indexToPos[piece_to_pos[{'B','U'}]];
                    // cout<<pos.x<<" "<<pos.y<<" "<<pos.z<<" "<<cnt<<endl;
             // UPPER LAYER 
             if(pos.y==1){
                  // FRONT
                  if(pos.z==1){
                          ans.push_back("F2");
                        handleRotation("F2");
                   }

                  // BACK 
                  else if(pos.z==-1){
                          ans.push_back("B2");
                        handleRotation("B2");
                   }
                   // RIGHT 
                   else if(pos.x==1){
                      ans.push_back("R2");
                        handleRotation("R2");
                   }
                   // LEFT
                   else {
                      ans.push_back("L2");
                        handleRotation("L2");
                   }
             }
             // MIDDLE LAYER
             else if(pos.y==0){

                // FRONT - RIGHT
                  if(pos.x==1 && pos.z==1){
                       vector<char>cubie1=pos_to_piece[12];
                        vector<char>cubie2=pos_to_piece[2];
                           
                        if(cubie1[0]=='U' && cubie1[1]=='R'){
                                 if(cubie2[0]=='F' && cubie2[1]=='U'){
                                        ans.push_back("R'");
                        handleRotation("R'");
                        ans.push_back("D'");
                        handleRotation("D'");
                        ans.push_back("R");
                        handleRotation("R");
                                 }
                                 else{
                                    ans.push_back("F");
                        handleRotation("F");
                                 }
                        }
                        else{
                            ans.push_back("R'");
                        handleRotation("R'");
                        }

                  }

                //   FRONT - LEFT
                  else if(pos.x==-1 && pos.z==1){
                             vector<char>cubie1=pos_to_piece[10];
                        vector<char>cubie2=pos_to_piece[2];

                        if(cubie1[0]=='U' && cubie1[1]=='L'){
                                 if(cubie2[0]=='F' && cubie2[1]=='U'){
                                        ans.push_back("L");
                        handleRotation("L");
                        ans.push_back("D");
                        handleRotation("D");
                        ans.push_back("L'");
                        handleRotation("L'");
                                 }
                                 else{
                                    ans.push_back("F'");
                        handleRotation("F'");
                                 }
                        }
                        else{
                            ans.push_back("L");
                        handleRotation("L");
                        }
                  }

                //   RIGHT - BACK
                  else if(pos.x==1 && pos.z==-1){
                          vector<char>cubie1=pos_to_piece[12];
                        vector<char>cubie2=pos_to_piece[20];

                        if(cubie1[0]=='U' && cubie1[1]=='R'){
                                 if(cubie2[0]=='U' && cubie2[1]=='B'){
                                        ans.push_back("R");
                        handleRotation("R");
                        ans.push_back("D'");
                        handleRotation("D'");
                        ans.push_back("R'");
                        handleRotation("R'");
                                 }
                                 else{
                                    ans.push_back("B'");
                        handleRotation("B'");
                                 }
                        }
                        else{
                            ans.push_back("R");
                        handleRotation("R");
                        }
                  }

                //   LEFT - BACK
                  else{
                      vector<char>cubie1=pos_to_piece[10];
                        vector<char>cubie2=pos_to_piece[20];

                        if(cubie1[0]=='U' && cubie1[1]=='L'){
                                 if(cubie2[0]=='U' && cubie2[1]=='B'){
                                        ans.push_back("L'");
                        handleRotation("L'");
                        ans.push_back("D");
                        handleRotation("D");
                        ans.push_back("L");
                        handleRotation("L");
                                 }
                                 else{
                                    ans.push_back("B");
                        handleRotation("B");
                                 }
                        }
                        else{
                            ans.push_back("L'");
                        handleRotation("L'");
                        }
                  }
             }
             // BOTTOM LAYER
             else{    
                     // FRONT
                   if(pos.z==1){

                         ans.push_back("D2");
                        handleRotation("D2");


                      
                       vector<char>cubie=pos_to_piece[26];
                       if(cubie[0]=='B' && cubie[1]=='U'){
                               ans.push_back("B2");
                        handleRotation("B2");
                       }
                       else{
                      ans.push_back("D'");
                        handleRotation("D'");
                         ans.push_back("R'");
                        handleRotation("R'");
                         ans.push_back("B");
                        handleRotation("B");
                         ans.push_back("R");
                        handleRotation("R");
                       }
                        
                   }
                   // BACK
                   else if(pos.z==-1){
                          vector<char>cubie=pos_to_piece[26];
                       if(cubie[0]=='B' && cubie[1]=='U'){
                               
                               ans.push_back("B2");
                        handleRotation("B2");
                       }
                       else{
                      ans.push_back("D'");
                        handleRotation("D'");
                         ans.push_back("R'");
                        handleRotation("R'");
                         ans.push_back("B");
                        handleRotation("B");
                         ans.push_back("R");
                        handleRotation("R");
                       }

                   }
                   // RIGHT 
                 else if(pos.x==1){

                      ans.push_back("D");
                      handleRotation("D");    
                    vector<char>cubie=pos_to_piece[26];
                       if(cubie[0]=='B' && cubie[1]=='U'){
                               ans.push_back("B2");
                        handleRotation("B2");
                       }
                       else{
                      ans.push_back("D'");
                        handleRotation("D'");
                         ans.push_back("R'");
                        handleRotation("R'");
                         ans.push_back("B");
                        handleRotation("B");
                         ans.push_back("R");
                        handleRotation("R");
                       }

                   }
                   // LEFT
                   else {
                      ans.push_back("D'");
                        handleRotation("D'");
                         vector<char>cubie=pos_to_piece[26];
                       if(cubie[0]=='B' && cubie[1]=='U'){
                               ans.push_back("B2");
                        handleRotation("B2");
                       }
                       else{
                      ans.push_back("D'");
                        handleRotation("D'");
                         ans.push_back("R'");
                        handleRotation("R'");
                         ans.push_back("B");
                        handleRotation("B");
                         ans.push_back("R");
                        handleRotation("R");
                       }
                   }
             }
      }

    }


    








     
          while(1){
              //  cerr << "DBG: entering loop step" << endl;

       // UPPER LEFT PIECE
      if(piece_to_pos.find({'U','L'})!=piece_to_pos.end()){
             Pos pos=indexToPos[piece_to_pos[{'U','L'}]];
            //  cout<<pos.x<<" "<<pos.y<<" "<<pos.z<<endl;

             // UPPER LAYER 
             if(pos.y==1){
                  // FRONT
                   if(pos.z==1){
                        ans.push_back("F2");
                        handleRotation("F2");
                   }
                   // BACK
                  
                  else if(pos.z==-1){
                          ans.push_back("B2");
                        handleRotation("B2");
                   }
                   // RIGHT 
                    else if(pos.x==1) {

                     
                      ans.push_back("R2");
                        handleRotation("R2");
                   }
                   

                   // LEFT
                   else {

                     break;
                     
                   }
             }
             // MIDDLE LAYER
             else if(pos.y==0){

                // FRONT - RIGHT
                  if(pos.x==1 && pos.z==1){
                       vector<char>cubie1=pos_to_piece[12];
                        vector<char>cubie2=pos_to_piece[2];

                        if(cubie1[0]=='U' && cubie1[1]=='R'){
                                 if(cubie2[0]=='F' && cubie2[1]=='U'){
                                        ans.push_back("R'");
                        handleRotation("R'");
                        ans.push_back("D'");
                        handleRotation("D'");
                        ans.push_back("R");
                        handleRotation("R");
                                 }
                                 else{
                                    ans.push_back("F");
                        handleRotation("F");
                                 }
                        }
                        else{
                            ans.push_back("R'");
                        handleRotation("R'");
                        }

                  }

                //   FRONT - LEFT
                  else if(pos.x==-1 && pos.z==1){
                             vector<char>cubie1=pos_to_piece[10];
                        vector<char>cubie2=pos_to_piece[2];

                        if(cubie1[0]=='U' && cubie1[1]=='L'){
                                 if(cubie2[0]=='F' && cubie2[1]=='U'){
                                        ans.push_back("L");
                        handleRotation("L");
                        ans.push_back("D");
                        handleRotation("D");
                        ans.push_back("L'");
                        handleRotation("L'");
                                 }
                                 else{
                                    ans.push_back("F'");
                        handleRotation("F'");
                                 }
                        }
                        else{
                            ans.push_back("L");
                        handleRotation("L");
                        }
                  }

                //   RIGHT - BACK
                  else if(pos.x==1 && pos.z==-1){
                          vector<char>cubie1=pos_to_piece[12];
                        vector<char>cubie2=pos_to_piece[20];

                        if(cubie1[0]=='U' && cubie1[1]=='R'){
                                 if(cubie2[0]=='U' && cubie2[1]=='B'){
                                        ans.push_back("R");
                        handleRotation("R");
                        ans.push_back("D'");
                        handleRotation("D'");
                        ans.push_back("R'");
                        handleRotation("R'");
                                 }
                                 else{
                                    ans.push_back("B'");
                        handleRotation("B'");
                                 }
                        }
                        else{
                            ans.push_back("R");
                        handleRotation("R");
                        }
                  }

                //   LEFT - BACK
                  else{
                      vector<char>cubie1=pos_to_piece[10];
                        vector<char>cubie2=pos_to_piece[20];

                        if(cubie1[0]=='U' && cubie1[1]=='L'){
                                 if(cubie2[0]=='U' && cubie2[1]=='B'){
                                        ans.push_back("L'");
                        handleRotation("L'");
                        ans.push_back("D");
                        handleRotation("D");
                        ans.push_back("L");
                        handleRotation("L");
                                 }
                                 else{
                                    ans.push_back("B");
                        handleRotation("B");
                                 }
                        }
                        else{
                            ans.push_back("L'");
                        handleRotation("L'");
                        }
                  }
             }
             // BOTTOM LAYER
             else{
                       // FRONT
                   if(pos.z==1){

                         ans.push_back("D'");
                        handleRotation("D'");


                      
                       vector<char>cubie=pos_to_piece[16];
                       if(cubie[0]=='L' && cubie[1]=='U'){
                               ans.push_back("L2");
                        handleRotation("L2");
                       }
                       else{
                      ans.push_back("D'");
                        handleRotation("D'");
                         ans.push_back("B'");
                        handleRotation("B'");
                         ans.push_back("L");
                        handleRotation("L");
                         ans.push_back("B");
                        handleRotation("B");
                       }
                        
                   }
                   // BACK
                   else if(pos.z==-1){
                        
                      ans.push_back("D");
                        handleRotation("D");
                       vector<char>cubie=pos_to_piece[16];
                       if(cubie[0]=='L' && cubie[1]=='U'){
                               ans.push_back("L2");
                        handleRotation("L2");
                       }
                       else{
                      ans.push_back("D'");
                        handleRotation("D'");
                         ans.push_back("B'");
                        handleRotation("B'");
                         ans.push_back("L");
                        handleRotation("L");
                         ans.push_back("B");
                        handleRotation("B");
                       }

                   }
                   // RIGHT 
                   if(pos.x==1){

                      ans.push_back("D2");
                      handleRotation("D2");    
                    vector<char>cubie=pos_to_piece[16];
                       if(cubie[0]=='L' && cubie[1]=='U'){
                               ans.push_back("L2");
                        handleRotation("L2");
                       }
                       else{
                      ans.push_back("D'");
                        handleRotation("D'");
                         ans.push_back("B'");
                        handleRotation("B'");
                         ans.push_back("L");
                        handleRotation("L");
                         ans.push_back("B");
                        handleRotation("B");
                       }

                   }
                   // LEFT
                   else {
                     vector<char>cubie=pos_to_piece[16];
                       if(cubie[0]=='L' && cubie[1]=='U'){
                               ans.push_back("L2");
                        handleRotation("L2");
                       }
                       else{
                      ans.push_back("D'");
                        handleRotation("D'");
                         ans.push_back("B'");
                        handleRotation("B'");
                         ans.push_back("L");
                        handleRotation("L");
                         ans.push_back("B");
                        handleRotation("B");
                       }
                   }
             }
      }




      else if(piece_to_pos.find({'L','U'})!=piece_to_pos.end()){
                     Pos pos=indexToPos[piece_to_pos[{'L','U'}]];
                 
             // UPPER LAYER 
             if(pos.y==1){
                  // FRONT
                  if(pos.z==1){
                          ans.push_back("F2");
                        handleRotation("F2");
                   }

                  // BACK 
                 else  if(pos.z==-1){
                          ans.push_back("B2");
                        handleRotation("B2");
                   }
                   // RIGHT 
                   else if(pos.x==1){
                      ans.push_back("R2");
                        handleRotation("R2");
                   }
                   // LEFT
                   else {
                      ans.push_back("L2");
                        handleRotation("L2");
                   }
             }
             // MIDDLE LAYER
             else if(pos.y==0){

                // FRONT - RIGHT
                  if(pos.x==1 && pos.z==1){
                       vector<char>cubie1=pos_to_piece[12];
                        vector<char>cubie2=pos_to_piece[2];

                        if(cubie1[0]=='U' && cubie1[1]=='R'){
                                 if(cubie2[0]=='F' && cubie2[1]=='U'){
                                        ans.push_back("R'");
                        handleRotation("R'");
                        ans.push_back("D'");
                        handleRotation("D'");
                        ans.push_back("R");
                        handleRotation("R");
                                 }
                                 else{
                                    ans.push_back("F");
                        handleRotation("F");
                                 }
                        }
                        else{
                            ans.push_back("R'");
                        handleRotation("R'");
                        }

                  }

                //   FRONT - LEFT
                  else if(pos.x==-1 && pos.z==1){
                             vector<char>cubie1=pos_to_piece[10];
                        vector<char>cubie2=pos_to_piece[2];

                        if(cubie1[0]=='U' && cubie1[1]=='L'){
                                 if(cubie2[0]=='F' && cubie2[1]=='U'){
                                        ans.push_back("L");
                        handleRotation("L");
                        ans.push_back("D");
                        handleRotation("D");
                        ans.push_back("L'");
                        handleRotation("L'");
                                 }
                                 else{
                                    ans.push_back("F'");
                        handleRotation("F'");
                                 }
                        }
                        else{
                            ans.push_back("L");
                        handleRotation("L");
                        }
                  }

                //   RIGHT - BACK
                  else if(pos.x==1 && pos.z==-1){
                          vector<char>cubie1=pos_to_piece[12];
                        vector<char>cubie2=pos_to_piece[20];

                        if(cubie1[0]=='U' && cubie1[1]=='R'){
                                 if(cubie2[0]=='U' && cubie2[1]=='B'){
                                        ans.push_back("R");
                        handleRotation("R");
                        ans.push_back("D'");
                        handleRotation("D'");
                        ans.push_back("R'");
                        handleRotation("R'");
                                 }
                                 else{
                                    ans.push_back("B'");
                        handleRotation("B'");
                                 }
                        }
                        else{
                            ans.push_back("R");
                        handleRotation("R");
                        }
                  }

                //   LEFT - BACK
                  else{
                      vector<char>cubie1=pos_to_piece[10];
                        vector<char>cubie2=pos_to_piece[20];

                        if(cubie1[0]=='U' && cubie1[1]=='L'){
                                 if(cubie2[0]=='U' && cubie2[1]=='B'){
                                        ans.push_back("L'");
                        handleRotation("L'");
                        ans.push_back("D");
                        handleRotation("D");
                        ans.push_back("L");
                        handleRotation("L");
                                 }
                                 else{
                                    ans.push_back("B");
                        handleRotation("B");
                                 }
                        }
                        else{
                            ans.push_back("L'");
                        handleRotation("L'");
                        }
                  }
             }
             // BOTTOM LAYER
             else{   
                   // FRONT 
                    if(pos.z==1){

                         ans.push_back("D'");
                        handleRotation("D'");


                      
                       vector<char>cubie=pos_to_piece[16];
                       if(cubie[0]=='L' && cubie[1]=='U'){
                               ans.push_back("L2");
                        handleRotation("L2");
                       }
                       else{
                      ans.push_back("D'");
                        handleRotation("D'");
                         ans.push_back("B'");
                        handleRotation("B'");
                         ans.push_back("L");
                        handleRotation("L");
                         ans.push_back("B");
                        handleRotation("B");
                       }
                        
                   }
                   // BACK
                   else if(pos.z==-1){
                        
                      ans.push_back("D");
                        handleRotation("D");
                       vector<char>cubie=pos_to_piece[16];
                       if(cubie[0]=='L' && cubie[1]=='U'){
                               ans.push_back("L2");
                        handleRotation("L2");
                       }
                       else{
                      ans.push_back("D'");
                        handleRotation("D'");
                         ans.push_back("B'");
                        handleRotation("B'");
                         ans.push_back("L");
                        handleRotation("L");
                         ans.push_back("B");
                        handleRotation("B");
                       }

                   }
                   // RIGHT 
                   if(pos.x==1){

                      ans.push_back("D2");
                      handleRotation("D2");    
                    vector<char>cubie=pos_to_piece[16];
                       if(cubie[0]=='L' && cubie[1]=='U'){
                               ans.push_back("L2");
                        handleRotation("L2");
                       }
                       else{
                      ans.push_back("D'");
                        handleRotation("D'");
                         ans.push_back("B'");
                        handleRotation("B'");
                         ans.push_back("L");
                        handleRotation("L");
                         ans.push_back("B");
                        handleRotation("B");
                       }

                   }
                   // LEFT
                   else {
                     vector<char>cubie=pos_to_piece[16];
                       if(cubie[0]=='L' && cubie[1]=='U'){
                               ans.push_back("L2");
                        handleRotation("L2");
                       }
                       else{
                      ans.push_back("D'");
                        handleRotation("D'");
                         ans.push_back("B'");
                        handleRotation("B'");
                         ans.push_back("L");
                        handleRotation("L");
                         ans.push_back("B");
                        handleRotation("B");
                       }
                   }
             
             }
      }



    }







}





 void solvingCornersOfUpperFace(){



    Pos pos;
        // FRONT-RIGHT-TOP
        

       
        while(1){

        if(piece_to_pos.find({'U','F','R'})!=piece_to_pos.end()){
            pos=indexToPos[piece_to_pos[{'U','F','R'}]];          
        }
        else if(piece_to_pos.find({'U','R','F'})!=piece_to_pos.end()){
                    pos=indexToPos[piece_to_pos[{'U','R','F'}]];
        }
        else if(piece_to_pos.find({'F','U','R'})!=piece_to_pos.end()){
                    pos=indexToPos[piece_to_pos[{'F','U','R'}]];
        }
        else if(piece_to_pos.find({'F','R','U'})!=piece_to_pos.end()){
                     pos=indexToPos[piece_to_pos[{'F','R','U'}]];
        }
        else if(piece_to_pos.find({'R','F','U'})!=piece_to_pos.end()){
                     pos=indexToPos[piece_to_pos[{'R','F','U'}]];
        }
        else if(piece_to_pos.find({'R','U','F'})!=piece_to_pos.end()){
                    pos=indexToPos[piece_to_pos[{'R','U','F'}]];
        }

        // TOP
         if(pos.y==1){
                 if(piece_to_pos.find({'U','F','R'})!=piece_to_pos.end() && pos.x==1 && pos.z==1){
                       break;
                 }

                 if(pos.x==1 && pos.z==1){
                           ans.push_back("F");
                        handleRotation("F");
                        ans.push_back("D");
                        handleRotation("D");
                        ans.push_back("F'");
                        handleRotation("F'");
                        ans.push_back("D'");
                        handleRotation("D'");

                 }
                 else if(pos.x==1 && pos.z==-1){
                           ans.push_back("R");
                        handleRotation("R");
                        ans.push_back("D");
                        handleRotation("D");
                        ans.push_back("R'");
                        handleRotation("R'");
                        ans.push_back("D'");
                        handleRotation("D'");

                 }
                 else if(pos.x==-1 && pos.z==1){
                           ans.push_back("L");
                        handleRotation("L");
                        ans.push_back("D");
                        handleRotation("D");
                        ans.push_back("L'");
                        handleRotation("L'");
                        ans.push_back("D'");
                        handleRotation("D'");

                 }
                 else{
                           ans.push_back("B");
                        handleRotation("B");
                        ans.push_back("D");
                        handleRotation("D");
                        ans.push_back("B'");
                        handleRotation("B'");
                        ans.push_back("D'");
                        handleRotation("D'");
                 }
                

         }
        //    BOTTOM
         else{
              
                 if(pos.x==1 && pos.z==1){
                          while(!(piece_to_pos.find({'U','F','R'})!=piece_to_pos.end() && indexToPos[piece_to_pos[{'U','F','R'}]].x==1 && indexToPos[piece_to_pos[{'U','F','R'}]].y==1 && indexToPos[piece_to_pos[{'U','F','R'}]].z==1 ) ){
                        handleRotation("F");
                        ans.push_back("F");
                        handleRotation("D");
                        ans.push_back("D");
                        ans.push_back("F'");
                        handleRotation("F'");
                        ans.push_back("D'");
                        handleRotation("D'");
                          }
                          break;
                 }

                 else if(pos.x==1 && pos.z==-1){
                       
                       
                        ans.push_back("D'");
                        handleRotation("D'");
                         while(!(piece_to_pos.find({'U','F','R'})!=piece_to_pos.end() && indexToPos[piece_to_pos[{'U','F','R'}]].x==1 && indexToPos[piece_to_pos[{'U','F','R'}]].y==1 && indexToPos[piece_to_pos[{'U','F','R'}]].z==1 ) ){
                        handleRotation("F");
                        ans.push_back("F");
                        handleRotation("D");
                        ans.push_back("D");
                        ans.push_back("F'");
                        handleRotation("F'");
                        ans.push_back("D'");
                        handleRotation("D'");
                          }
                          break;
                 }

                else if(pos.x==-1 && pos.z==1){
                       ans.push_back("D");
                        handleRotation("D");
                        while(!(piece_to_pos.find({'U','F','R'})!=piece_to_pos.end() && indexToPos[piece_to_pos[{'U','F','R'}]].x==1 && indexToPos[piece_to_pos[{'U','F','R'}]].y==1 && indexToPos[piece_to_pos[{'U','F','R'}]].z==1 ) ){
                        handleRotation("F");
                        ans.push_back("F");
                        handleRotation("D");
                        ans.push_back("D");
                        ans.push_back("F'");
                        handleRotation("F'");
                        ans.push_back("D'");
                        handleRotation("D'");
                          }
                          break;
                }
                else{
                     ans.push_back("D2");
                        handleRotation("D2");
                       while(!(piece_to_pos.find({'U','F','R'})!=piece_to_pos.end() && indexToPos[piece_to_pos[{'U','F','R'}]].x==1 && indexToPos[piece_to_pos[{'U','F','R'}]].y==1 && indexToPos[piece_to_pos[{'U','F','R'}]].z==1 ) ){
                        handleRotation("F");
                        ans.push_back("F");
                        handleRotation("D");
                        ans.push_back("D");
                        ans.push_back("F'");
                        handleRotation("F'");
                        ans.push_back("D'");
                        handleRotation("D'");
                          }
                          break;
                }
         }
        }





        // UP-RIGHT-BACK

        while(1){

        if(piece_to_pos.find({'U','R','B'})!=piece_to_pos.end()){
            pos=indexToPos[piece_to_pos[{'U','R','B'}]];
                    
        }
        else if(piece_to_pos.find({'U','B','R'})!=piece_to_pos.end()){
                    pos=indexToPos[piece_to_pos[{'U','B','R'}]];
        }
        else if(piece_to_pos.find({'R','U','B'})!=piece_to_pos.end()){
                    pos=indexToPos[piece_to_pos[{'R','U','B'}]];
        }
        else if(piece_to_pos.find({'R','B','U'})!=piece_to_pos.end()){
                     pos=indexToPos[piece_to_pos[{'R','B','U'}]];
        }
        else if(piece_to_pos.find({'B','U','R'})!=piece_to_pos.end()){
                     pos=indexToPos[piece_to_pos[{'B','U','R'}]];
        }
        else if(piece_to_pos.find({'B','R','U'})!=piece_to_pos.end()){
                    pos=indexToPos[piece_to_pos[{'B','R','U'}]];
        }

        // TOP
         if(pos.y==1){
                 if(piece_to_pos.find({'U','R','B'})!=piece_to_pos.end() && pos.x==1 && pos.z==-1){
                       break;
                 }

                 if(pos.x==1 && pos.z==1){
                           ans.push_back("F");
                        handleRotation("F");
                        ans.push_back("D");
                        handleRotation("D");
                        ans.push_back("F'");
                        handleRotation("F'");
                        ans.push_back("D'");
                        handleRotation("D'");

                 }
                 else if(pos.x==1 && pos.z==-1){
                           ans.push_back("R");
                        handleRotation("R");
                        ans.push_back("D");
                        handleRotation("D");
                        ans.push_back("R'");
                        handleRotation("R'");
                        ans.push_back("D'");
                        handleRotation("D'");

                 }
                 else if(pos.x==-1 && pos.z==1){
                           ans.push_back("L");
                        handleRotation("L");
                        ans.push_back("D");
                        handleRotation("D");
                        ans.push_back("L'");
                        handleRotation("L'");
                        ans.push_back("D'");
                        handleRotation("D'");

                 }
                 else{
                           ans.push_back("B");
                        handleRotation("B");
                        ans.push_back("D");
                        handleRotation("D");
                        ans.push_back("B'");
                        handleRotation("B'");
                        ans.push_back("D'");
                        handleRotation("D'");
                 }
                

         }
        //    BOTTOM
         else{
                     
                        
                 if(pos.x==1 && pos.z==1){
                    ans.push_back("D");
                        handleRotation("D");
                          while(!(piece_to_pos.find({'U','R','B'})!=piece_to_pos.end() && indexToPos[piece_to_pos[{'U','R','B'}]].x==1 && indexToPos[piece_to_pos[{'U','R','B'}]].y==1 && indexToPos[piece_to_pos[{'U','R','B'}]].z==-1 ) ){
                        ans.push_back("R");
                        handleRotation("R");
                        ans.push_back("D");
                        handleRotation("D");
                        ans.push_back("R'");
                        handleRotation("R'");
                        ans.push_back("D'");
                        handleRotation("D'");
                          }
                          break;
                 }

                 else if(pos.x==1 && pos.z==-1){
                       
                      
                          while(!(piece_to_pos.find({'U','R','B'})!=piece_to_pos.end() && indexToPos[piece_to_pos[{'U','R','B'}]].x==1 && indexToPos[piece_to_pos[{'U','R','B'}]].y==1 && indexToPos[piece_to_pos[{'U','R','B'}]].z==-1 ) ){
                        ans.push_back("R");
                        handleRotation("R");
                        ans.push_back("D");
                        handleRotation("D");
                        ans.push_back("R'");
                        handleRotation("R'");
                        ans.push_back("D'");
                        handleRotation("D'");
                          }
                          break;
                 }

                else if(pos.x==-1 && pos.z==1){
                       ans.push_back("D2");
                        handleRotation("D2");
                        while(!(piece_to_pos.find({'U','R','B'})!=piece_to_pos.end() && indexToPos[piece_to_pos[{'U','R','B'}]].x==1 && indexToPos[piece_to_pos[{'U','R','B'}]].y==1 && indexToPos[piece_to_pos[{'U','R','B'}]].z==-1 ) ){
                        ans.push_back("R");
                        handleRotation("R");
                        ans.push_back("D");
                        handleRotation("D");
                        ans.push_back("R'");
                        handleRotation("R'");
                        ans.push_back("D'");
                        handleRotation("D'");
                          }
                          break;
                }
                else{
                     ans.push_back("D'");
                        handleRotation("D'");
                        while(!(piece_to_pos.find({'U','R','B'})!=piece_to_pos.end() && indexToPos[piece_to_pos[{'U','R','B'}]].x==1 && indexToPos[piece_to_pos[{'U','R','B'}]].y==1 && indexToPos[piece_to_pos[{'U','R','B'}]].z==-1 ) ){
                        ans.push_back("R");
                        handleRotation("R");
                        ans.push_back("D");
                        handleRotation("D");
                        ans.push_back("R'");
                        handleRotation("R'");
                        ans.push_back("D'");
                        handleRotation("D'");
                          }
                          break;
                }
         }
        }





        // UP-FRONT-LEFT
         while(1){

        if(piece_to_pos.find({'U','F','L'})!=piece_to_pos.end()){
            pos=indexToPos[piece_to_pos[{'U','F','L'}]];          
        }
        else if(piece_to_pos.find({'U','L','F'})!=piece_to_pos.end()){
                    pos=indexToPos[piece_to_pos[{'U','L','F'}]];
        }
        else if(piece_to_pos.find({'F','U','L'})!=piece_to_pos.end()){
                    pos=indexToPos[piece_to_pos[{'F','U','L'}]];
        }
        else if(piece_to_pos.find({'F','L','U'})!=piece_to_pos.end()){
                     pos=indexToPos[piece_to_pos[{'F','L','U'}]];
        }
        else if(piece_to_pos.find({'L','U','F'})!=piece_to_pos.end()){
                     pos=indexToPos[piece_to_pos[{'L','U','F'}]];
        }
        else if(piece_to_pos.find({'L','F','U'})!=piece_to_pos.end()){
                    pos=indexToPos[piece_to_pos[{'L','F','U'}]];
        }

        // TOP
         if(pos.y==1){
                 if(piece_to_pos.find({'U','F','L'})!=piece_to_pos.end() && pos.x==-1 && pos.z==1){
                       break;
                 }

                 if(pos.x==1 && pos.z==1){
                           ans.push_back("F");
                        handleRotation("F");
                        ans.push_back("D");
                        handleRotation("D");
                        ans.push_back("F'");
                        handleRotation("F'");
                        ans.push_back("D'");
                        handleRotation("D'");

                 }
                 else if(pos.x==1 && pos.z==-1){
                           ans.push_back("R");
                        handleRotation("R");
                        ans.push_back("D");
                        handleRotation("D");
                        ans.push_back("R'");
                        handleRotation("R'");
                        ans.push_back("D'");
                        handleRotation("D'");

                 }
                 else if(pos.x==-1 && pos.z==1){
                           ans.push_back("L");
                        handleRotation("L");
                        ans.push_back("D");
                        handleRotation("D");
                        ans.push_back("L'");
                        handleRotation("L'");
                        ans.push_back("D'");
                        handleRotation("D'");

                 }
                 else{
                           ans.push_back("B");
                        handleRotation("B");
                        ans.push_back("D");
                        handleRotation("D");
                        ans.push_back("B'");
                        handleRotation("B'");
                        ans.push_back("D'");
                        handleRotation("D'");
                 }
                

         }
        //    BOTTOM
         else{
                     
                        
                 if(pos.x==1 && pos.z==1){
                    ans.push_back("D'");
                        handleRotation("D'");
                          while(!(piece_to_pos.find({'U','F','L'})!=piece_to_pos.end() && indexToPos[piece_to_pos[{'U','F','L'}]].x==-1 && indexToPos[piece_to_pos[{'U','F','L'}]].y==1 && indexToPos[piece_to_pos[{'U','F','L'}]].z==1 ) ){
                        ans.push_back("L");
                        handleRotation("L");
                        ans.push_back("D");
                        handleRotation("D");
                        ans.push_back("L'");
                        handleRotation("L'");
                        ans.push_back("D'");
                        handleRotation("D'");
                          }
                          break;
                 }

                 else if(pos.x==1 && pos.z==-1){
                       
                      
                         ans.push_back("D2");
                        handleRotation("D2");
                           while(!(piece_to_pos.find({'U','F','L'})!=piece_to_pos.end() && indexToPos[piece_to_pos[{'U','F','L'}]].x==-1 && indexToPos[piece_to_pos[{'U','F','L'}]].y==1 && indexToPos[piece_to_pos[{'U','F','L'}]].z==1 ) ){
                        ans.push_back("L");
                        handleRotation("L");
                        ans.push_back("D");
                        handleRotation("D");
                        ans.push_back("L'");
                        handleRotation("L'");
                        ans.push_back("D'");
                        handleRotation("D'");
                          }
                          break;
                 }

                else if(pos.x==-1 && pos.z==1){
                             
                          while(!(piece_to_pos.find({'U','F','L'})!=piece_to_pos.end() && indexToPos[piece_to_pos[{'U','F','L'}]].x==-1 && indexToPos[piece_to_pos[{'U','F','L'}]].y==1 && indexToPos[piece_to_pos[{'U','F','L'}]].z==1 ) ){
                                // cout<<indexToPos[piece_to_pos[{'U','F','L'}]].x<< " "<<indexToPos[piece_to_pos[{'U','F','L'}]].y<<" "<< indexToPos[piece_to_pos[{'U','F','L'}]].z<<endl; 
                        ans.push_back("L");
                        handleRotation("L");
                        ans.push_back("D");
                        handleRotation("D");
                        ans.push_back("L'");
                        handleRotation("L'");
                        ans.push_back("D'");
                        handleRotation("D'");
                          }
                        //   cout<<indexToPos[piece_to_pos[{'U','F','L'}]].x<< " "<<indexToPos[piece_to_pos[{'U','F','L'}]].y<<" "<< indexToPos[piece_to_pos[{'U','F','L'}]].z<<endl; 
                          break;
                }
                else{
                     ans.push_back("D");
                        handleRotation("D");
                          while(!(piece_to_pos.find({'U','F','L'})!=piece_to_pos.end() && indexToPos[piece_to_pos[{'U','F','L'}]].x==-1 && indexToPos[piece_to_pos[{'U','F','L'}]].y==1 && indexToPos[piece_to_pos[{'U','F','L'}]].z==1 ) ){
                        ans.push_back("L");
                        handleRotation("L");
                        ans.push_back("D");
                        handleRotation("D");
                        ans.push_back("L'");
                        handleRotation("L'");
                        ans.push_back("D'");
                        handleRotation("D'");
                          }
                          break;
                }
         }
        }




        
        // UP-BACK-LEFT
         while(1){

        if(piece_to_pos.find({'U','B','L'})!=piece_to_pos.end()){
            pos=indexToPos[piece_to_pos[{'U','B','L'}]];          
        }
        else if(piece_to_pos.find({'U','L','B'})!=piece_to_pos.end()){
                    pos=indexToPos[piece_to_pos[{'U','L','B'}]];
        }
        else if(piece_to_pos.find({'B','U','L'})!=piece_to_pos.end()){
                    pos=indexToPos[piece_to_pos[{'B','U','L'}]];
        }
        else if(piece_to_pos.find({'B','L','U'})!=piece_to_pos.end()){
                     pos=indexToPos[piece_to_pos[{'B','L','U'}]];
        }
        else if(piece_to_pos.find({'L','U','B'})!=piece_to_pos.end()){
                     pos=indexToPos[piece_to_pos[{'L','U','B'}]];
        }
        else if(piece_to_pos.find({'L','B','U'})!=piece_to_pos.end()){
                    pos=indexToPos[piece_to_pos[{'L','B','U'}]];
        }

        // TOP
         if(pos.y==1){
                 if(piece_to_pos.find({'U','L','B'})!=piece_to_pos.end() && pos.x==-1 && pos.z==-1){
                       break;
                 }

                 if(pos.x==1 && pos.z==1){
                           ans.push_back("F");
                        handleRotation("F");
                        ans.push_back("D");
                        handleRotation("D");
                        ans.push_back("F'");
                        handleRotation("F'");
                        ans.push_back("D'");
                        handleRotation("D'");

                 }
                 else if(pos.x==1 && pos.z==-1){
                           ans.push_back("R");
                        handleRotation("R");
                        ans.push_back("D");
                        handleRotation("D");
                        ans.push_back("R'");
                        handleRotation("R'");
                        ans.push_back("D'");
                        handleRotation("D'");

                 }
                 else if(pos.x==-1 && pos.z==1){
                           ans.push_back("L");
                        handleRotation("L");
                        ans.push_back("D");
                        handleRotation("D");
                        ans.push_back("L'");
                        handleRotation("L'");
                        ans.push_back("D'");
                        handleRotation("D'");

                 }
                 else{
                           ans.push_back("B");
                        handleRotation("B");
                        ans.push_back("D");
                        handleRotation("D");
                        ans.push_back("B'");
                        handleRotation("B'");
                        ans.push_back("D'");
                        handleRotation("D'");
                 }
                

         }
        //    BOTTOM
         else{
                     
                        
                 if(pos.x==1 && pos.z==1){
                    ans.push_back("D2");
                        handleRotation("D2");
                          while(!(piece_to_pos.find({'U','L','B'})!=piece_to_pos.end() && indexToPos[piece_to_pos[{'U','L','B'}]].x==-1 && indexToPos[piece_to_pos[{'U','L','B'}]].y==1 && indexToPos[piece_to_pos[{'U','L','B'}]].z==-1 ) ){
                        ans.push_back("B");
                        handleRotation("B");
                        ans.push_back("D");
                        handleRotation("D");
                        ans.push_back("B'");
                        handleRotation("B'");
                        ans.push_back("D'");
                        handleRotation("D'");
                          }
                          break;
                 }

                 else if(pos.x==1 && pos.z==-1){
                       
                       ans.push_back("D");
                        handleRotation("D");
                          while(!(piece_to_pos.find({'U','L','B'})!=piece_to_pos.end() && indexToPos[piece_to_pos[{'U','L','B'}]].x==-1 && indexToPos[piece_to_pos[{'U','L','B'}]].y==1 && indexToPos[piece_to_pos[{'U','L','B'}]].z==-1 ) ){
                        ans.push_back("B");
                        handleRotation("B");
                        ans.push_back("D");
                        handleRotation("D");
                        ans.push_back("B'");
                        handleRotation("B'");
                        ans.push_back("D'");
                        handleRotation("D'");
                          }
                          break;
                 }

                else if(pos.x==-1 && pos.z==1){
                         ans.push_back("D'");
                        handleRotation("D'");
                          while(!(piece_to_pos.find({'U','L','B'})!=piece_to_pos.end() && indexToPos[piece_to_pos[{'U','L','B'}]].x==-1 && indexToPos[piece_to_pos[{'U','L','B'}]].y==1 && indexToPos[piece_to_pos[{'U','L','B'}]].z==-1 ) ){
                        ans.push_back("B");
                        handleRotation("B");
                        ans.push_back("D");
                        handleRotation("D");
                        ans.push_back("B'");
                        handleRotation("B'");
                        ans.push_back("D'");
                        handleRotation("D'");
                          }
                          break;
                }
                else{

                          while(!(piece_to_pos.find({'U','L','B'})!=piece_to_pos.end() && indexToPos[piece_to_pos[{'U','L','B'}]].x==-1 && indexToPos[piece_to_pos[{'U','L','B'}]].y==1 && indexToPos[piece_to_pos[{'U','L','B'}]].z==-1 ) ){
                        ans.push_back("B");
                        handleRotation("B");
                        ans.push_back("D");
                        handleRotation("D");
                        ans.push_back("B'");
                        handleRotation("B'");
                        ans.push_back("D'");
                        handleRotation("D'");
                          }
                          break;
                }
         }
        }



 }




 void secondLayer(){
        int cnt=100;
           while(1){
               bool f=0;


              
               if((pos_to_piece[8][0]!='D' && pos_to_piece[8][1]!='D') ||  (pos_to_piece[16][0]!='D' && pos_to_piece[16][1]!='D') || (pos_to_piece[18][0]!='D' && pos_to_piece[18][1]!='D') || (pos_to_piece[26][0]!='D' && pos_to_piece[26][1]!='D')){
                     f=1;
               }
                  
                    //  cout<<f<<" ";
               if(f==0){ 
                    
                   if(pos_to_piece[4][0]!='F'){
                        // cout<<"4rg";
                          ans.push_back("D");
                        handleRotation("D");
                         ans.push_back("L");
                        handleRotation("L");
                          ans.push_back("D'");
                        handleRotation("D'");
                         ans.push_back("L'");
                        handleRotation("L'");
                          ans.push_back("D'");
                        handleRotation("D'");
                         ans.push_back("F'");
                        handleRotation("F'");
                          ans.push_back("D");
                        handleRotation("D");
                         ans.push_back("F");
                        handleRotation("F");

                   }
                   else  if(pos_to_piece[6][0]!='F'){
                    //   cout<<"5rg";
                          ans.push_back("D'");
                        handleRotation("D'");
                         ans.push_back("R'");
                        handleRotation("R'");
                          ans.push_back("D");
                        handleRotation("D");
                         ans.push_back("R");
                        handleRotation("R");
                          ans.push_back("D");
                        handleRotation("D");
                         ans.push_back("F");
                        handleRotation("F");
                          ans.push_back("D'");
                        handleRotation("D'");
                         ans.push_back("F'");
                        handleRotation("F'");

                   }
                   else if(pos_to_piece[24][1]!='B'){

                          ans.push_back("D");
                        handleRotation("D");
                         ans.push_back("R");
                        handleRotation("R");
                          ans.push_back("D'");
                        handleRotation("D'");
                         ans.push_back("R'");
                        handleRotation("R'");
                          ans.push_back("D'");
                        handleRotation("D'");
                         ans.push_back("B'");
                        handleRotation("B'");
                          ans.push_back("D");
                        handleRotation("D");
                         ans.push_back("B");
                        handleRotation("B");

                   }
                    else if(pos_to_piece[22][1]!='B'){
                          ans.push_back("D'");
                        handleRotation("D'");
                         ans.push_back("L'");
                        handleRotation("L'");
                          ans.push_back("D");
                        handleRotation("D");
                         ans.push_back("L");
                        handleRotation("L");
                          ans.push_back("D");
                        handleRotation("D");
                         ans.push_back("B");
                        handleRotation("B");
                          ans.push_back("D'");
                        handleRotation("D'");
                         ans.push_back("B'");
                        handleRotation("B'");

                   }



                           
                    else if(pos_to_piece[6][1]!='R'){

                          ans.push_back("D");
                        handleRotation("D");
                         ans.push_back("F");
                        handleRotation("F");
                          ans.push_back("D'");
                        handleRotation("D'");
                         ans.push_back("F'");
                        handleRotation("F'");
                          ans.push_back("D'");
                        handleRotation("D'");
                         ans.push_back("R'");
                        handleRotation("R'");
                          ans.push_back("D");
                        handleRotation("D");
                         ans.push_back("R");
                        handleRotation("R");

                   }
                    else if(pos_to_piece[24][0]!='R'){
                          ans.push_back("D'");
                        handleRotation("D'");
                         ans.push_back("B'");
                        handleRotation("B'");
                          ans.push_back("D");
                        handleRotation("D");
                         ans.push_back("B");
                        handleRotation("B");
                          ans.push_back("D");
                        handleRotation("D");
                         ans.push_back("R");
                        handleRotation("R");
                          ans.push_back("D'");
                        handleRotation("D'");
                         ans.push_back("R'");
                        handleRotation("R'");

                   }


                    else if(pos_to_piece[4][1]!='L'){

                        ans.push_back("D'");
                        handleRotation("D'");
                        ans.push_back("F'");
                        handleRotation("F'");
                        ans.push_back("D");
                        handleRotation("D");
                        ans.push_back("F");
                        handleRotation("F");
                        ans.push_back("D");
                        handleRotation("D");
                        ans.push_back("L");
                        handleRotation("L");
                        ans.push_back("D'");
                        handleRotation("D'");
                        ans.push_back("L'");
                        handleRotation("L'");

                   }
                    else if(pos_to_piece[22][0]!='L'){
                          ans.push_back("D");
                        handleRotation("D");
                        ans.push_back("B");
                        handleRotation("B");
                        ans.push_back("D'");
                        handleRotation("D'");
                        ans.push_back("B'");
                        handleRotation("B'");
                        ans.push_back("D'");
                        handleRotation("D'");
                        ans.push_back("L'");
                        handleRotation("L'");
                        ans.push_back("L");
                        handleRotation("L");
                        ans.push_back("D");
                        handleRotation("D");

                   }
                   else{
                    break;
                   }
                   

               }
               else{

                    // DOWN-FRONT
                    if(pos_to_piece[8][0]!='D' && pos_to_piece[8][1]!='D'){
                           // RIGHT FACE
                              if(pos_to_piece[8][0]=='R'){
                                       ans.push_back("D");
                        handleRotation("D");

                        // MOVE TO FRONT SIDE
                                if(pos_to_piece[18][1]=='F'){
                        ans.push_back("D");
                        handleRotation("D");
                         ans.push_back("F");
                        handleRotation("F");
                          ans.push_back("D'");
                        handleRotation("D'");
                         ans.push_back("F'");
                        handleRotation("F'");
                          ans.push_back("D'");
                        handleRotation("D'");
                         ans.push_back("R'");
                        handleRotation("R'");
                          ans.push_back("D");
                        handleRotation("D");
                         ans.push_back("R");
                        handleRotation("R");
                                }

                                // MOVE TO BACK SIDE
                                else {
                        ans.push_back("D'");
                        handleRotation("D'");
                         ans.push_back("B'");
                        handleRotation("B'");
                          ans.push_back("D");
                        handleRotation("D");
                         ans.push_back("B");
                        handleRotation("B");
                          ans.push_back("D");
                        handleRotation("D");
                         ans.push_back("R");
                        handleRotation("R");
                          ans.push_back("D'");
                        handleRotation("D'");
                         ans.push_back("R'");
                        handleRotation("R'");
                                }
                              }

                              // BACK FACE

                              else  if(pos_to_piece[8][0]=='B'){
                                       ans.push_back("D2");
                        handleRotation("D2");

                        // MOVE TO RIGHT SIDE
                                if(pos_to_piece[26][1]=='R'){
                      ans.push_back("D");
                        handleRotation("D");
                         ans.push_back("R");
                        handleRotation("R");
                          ans.push_back("D'");
                        handleRotation("D'");
                         ans.push_back("R'");
                        handleRotation("R'");
                          ans.push_back("D'");
                        handleRotation("D'");
                         ans.push_back("B'");
                        handleRotation("B'");
                          ans.push_back("D");
                        handleRotation("D");
                         ans.push_back("B");
                        handleRotation("B");
                                }

                                // MOVE TO LEFT SIDE
                                else {
                        ans.push_back("D'");
                        handleRotation("D'");
                         ans.push_back("L'");
                        handleRotation("L'");
                          ans.push_back("D");
                        handleRotation("D");
                         ans.push_back("L");
                        handleRotation("L");
                          ans.push_back("D");
                        handleRotation("D");
                         ans.push_back("B");
                        handleRotation("B");
                          ans.push_back("D'");
                        handleRotation("D'");
                         ans.push_back("B'");
                        handleRotation("B'");
                                }
                              }



                              // LEFT FACE
                               else  if(pos_to_piece[8][0]=='L'){
                                       ans.push_back("D'");
                        handleRotation("D'");

                        // MOVE TO FRONT SIDE
                                if(pos_to_piece[16][1]=='F'){
                      ans.push_back("D'");
                        handleRotation("D'");
                         ans.push_back("F'");
                        handleRotation("F'");
                          ans.push_back("D");
                        handleRotation("D");
                         ans.push_back("F");
                        handleRotation("F");
                          ans.push_back("D");
                        handleRotation("D");
                         ans.push_back("L");
                        handleRotation("L");
                          ans.push_back("D'");
                        handleRotation("D'");
                         ans.push_back("L'");
                        handleRotation("L'");
                                }

                                // MOVE TO BACK SIDE
                                else {
                        ans.push_back("D");
                        handleRotation("D");
                         ans.push_back("B");
                        handleRotation("B");
                          ans.push_back("D'");
                        handleRotation("D'");
                         ans.push_back("B'");
                        handleRotation("B'");
                          ans.push_back("D'");
                        handleRotation("D'");
                         ans.push_back("L'");
                        handleRotation("L'");
                          ans.push_back("D");
                        handleRotation("D");
                         ans.push_back("L");
                        handleRotation("L");
                                }
                              }

                           // FRONT FACE
                             else  if(pos_to_piece[8][0]=='F'){

                        // MOVE TO LEFT SIDE
                                if(pos_to_piece[8][1]=='L'){
                      ans.push_back("D");
                        handleRotation("D");
                         ans.push_back("L");
                        handleRotation("L");
                          ans.push_back("D'");
                        handleRotation("D'");
                         ans.push_back("L'");
                        handleRotation("L'");
                          ans.push_back("D'");
                        handleRotation("D'");
                         ans.push_back("F'");
                        handleRotation("F'");
                          ans.push_back("D");
                        handleRotation("D");
                         ans.push_back("F");
                        handleRotation("F");
                                }

                                // MOVE TO RIGHT SIDE
                                else {
                        ans.push_back("D'");
                        handleRotation("D'");
                         ans.push_back("R'");
                        handleRotation("R'");
                          ans.push_back("D");
                        handleRotation("D");
                         ans.push_back("R");
                        handleRotation("R");
                          ans.push_back("D");
                        handleRotation("D");
                         ans.push_back("F");
                        handleRotation("F");
                          ans.push_back("D'");
                        handleRotation("D'");
                         ans.push_back("F'");
                        handleRotation("F'");
                                }
                              }



                    }


                      // DOWN-RIGHT
                   else if(pos_to_piece[18][0]!='D' && pos_to_piece[18][1]!='D'){
                        
                           // RIGHT FACE
                              if(pos_to_piece[18][0]=='R'){
                                    

                        // MOVE TO FRONT SIDE
                                if(pos_to_piece[18][1]=='F'){
                        ans.push_back("D");
                        handleRotation("D");
                         ans.push_back("F");
                        handleRotation("F");
                          ans.push_back("D'");
                        handleRotation("D'");
                         ans.push_back("F'");
                        handleRotation("F'");
                          ans.push_back("D'");
                        handleRotation("D'");
                         ans.push_back("R'");
                        handleRotation("R'");
                          ans.push_back("D");
                        handleRotation("D");
                         ans.push_back("R");
                        handleRotation("R");
                                }

                                // MOVE TO BACK SIDE
                                else {
                        ans.push_back("D'");
                        handleRotation("D'");
                         ans.push_back("B'");
                        handleRotation("B'");
                          ans.push_back("D");
                        handleRotation("D");
                         ans.push_back("B");
                        handleRotation("B");
                          ans.push_back("D");
                        handleRotation("D");
                         ans.push_back("R");
                        handleRotation("R");
                          ans.push_back("D'");
                        handleRotation("D'");
                         ans.push_back("R'");
                        handleRotation("R'");
                                }
                              }

                              // BACK FACE

                              else  if(pos_to_piece[18][0]=='B'){
                                       ans.push_back("D");
                        handleRotation("D");

                        
                              }



                              // LEFT FACE
                               else  if(pos_to_piece[18][0]=='L'){
                                       ans.push_back("D2");
                        handleRotation("D2");

                              }

                           // FRONT FACE
                             else  if(pos_to_piece[18][0]=='F'){
                                   ans.push_back("D'");
                        handleRotation("D'");
                        
                              }



                    }


                    // DOWN BACK

                   
                   else if(pos_to_piece[26][0]!='D' && pos_to_piece[26][1]!='D'){
                           // RIGHT FACE
                              if(pos_to_piece[26][0]=='R'){
                                       ans.push_back("D'");
                        handleRotation("D'");

                       
                              }

                              // BACK FACE

                              else  if(pos_to_piece[26][0]=='B'){
                                       

                        // MOVE TO RIGHT SIDE
                                if(pos_to_piece[26][1]=='R'){
                      ans.push_back("D");
                        handleRotation("D");
                         ans.push_back("R");
                        handleRotation("R");
                          ans.push_back("D'");
                        handleRotation("D'");
                         ans.push_back("R'");
                        handleRotation("R'");
                          ans.push_back("D'");
                        handleRotation("D'");
                         ans.push_back("B'");
                        handleRotation("B'");
                          ans.push_back("D");
                        handleRotation("D");
                         ans.push_back("B");
                        handleRotation("B");
                                }

                                // MOVE TO LEFT SIDE
                                else {
                        ans.push_back("D'");
                        handleRotation("D'");
                         ans.push_back("L'");
                        handleRotation("L'");
                          ans.push_back("D");
                        handleRotation("D");
                         ans.push_back("L");
                        handleRotation("L");
                          ans.push_back("D");
                        handleRotation("D");
                         ans.push_back("B");
                        handleRotation("B");
                          ans.push_back("D'");
                        handleRotation("D'");
                         ans.push_back("B'");
                        handleRotation("B'");
                                }
                              }



                              // LEFT FACE
                               else  if(pos_to_piece[26][0]=='L'){
                                       ans.push_back("D");
                        handleRotation("D");

                              }

                           // FRONT FACE
                             else  if(pos_to_piece[26][0]=='F'){

                                     ans.push_back("D2");
                        handleRotation("D2");
                              }



                    }


                        // DOWN LEFT
                    else if(pos_to_piece[16][0]!='D' && pos_to_piece[16][1]!='D'){
                           // RIGHT FACE
                              if(pos_to_piece[16][0]=='R'){
                                       ans.push_back("D2");
                        handleRotation("D2");

                       
                              }

                              // BACK FACE

                              else  if(pos_to_piece[16][0]=='B'){
                                       ans.push_back("D'");
                        handleRotation("D'");

                     
                              }



                              // LEFT FACE
                               else  if(pos_to_piece[16][0]=='L'){
                                      
                        // MOVE TO FRONT SIDE
                                if(pos_to_piece[16][1]=='F'){
                      ans.push_back("D'");
                        handleRotation("D'");
                         ans.push_back("F'");
                        handleRotation("F'");
                          ans.push_back("D");
                        handleRotation("D");
                         ans.push_back("F");
                        handleRotation("F");
                          ans.push_back("D");
                        handleRotation("D");
                         ans.push_back("L");
                        handleRotation("L");
                          ans.push_back("D'");
                        handleRotation("D'");
                         ans.push_back("L'");
                        handleRotation("L'");
                                }

                                // MOVE TO BACK SIDE
                                else {
                        ans.push_back("D");
                        handleRotation("D");
                         ans.push_back("B");
                        handleRotation("B");
                          ans.push_back("D'");
                        handleRotation("D'");
                         ans.push_back("B'");
                        handleRotation("B'");
                          ans.push_back("D'");
                        handleRotation("D'");
                         ans.push_back("L'");
                        handleRotation("L'");
                          ans.push_back("D");
                        handleRotation("D");
                         ans.push_back("L");
                        handleRotation("L");
                                }
                              }

                           // FRONT FACE
                             else  if(pos_to_piece[16][0]=='F'){

                        ans.push_back("D");
                        handleRotation("D");

                              }



                    }


                    
               }


                    
               }




           
 }





  void downCross(){

    int   cnt=100;
        while(1){
              // CROSS CASE

                 if(pos_to_piece[8][1]=='D' && pos_to_piece[16][1]=='D' && pos_to_piece[18][1]=='D' && pos_to_piece[26][1]=='D'){
                    
                      break;
                 }


                   // LINE

        if((pos_to_piece[16][1]=='D' && pos_to_piece[18][1]=='D')){
                        
                     ans.push_back("B");
                        handleRotation("B");
                         ans.push_back("R");
                        handleRotation("R");
                         ans.push_back("D");
                        handleRotation("D");
                         ans.push_back("R'");
                        handleRotation("R'");
                         ans.push_back("D'");
                        handleRotation("D'");
                         ans.push_back("B'");
                        handleRotation("B'");
        }
        else if(pos_to_piece[8][1]=='D' && pos_to_piece[26][1]=='D'){
              
                        ans.push_back("D");
                        handleRotation("D");
                       ans.push_back("B");
                        handleRotation("B");
                         ans.push_back("R");
                        handleRotation("R");
                         ans.push_back("D");
                        handleRotation("D");
                         ans.push_back("R'");
                        handleRotation("R'");
                         ans.push_back("D'");
                        handleRotation("D'");
                         ans.push_back("B'");
                        handleRotation("B'");
        }


        // L CASE

       else if(pos_to_piece[7][2]=='D' && pos_to_piece[8][1]=='D' && pos_to_piece[16][1]=='D'){   
          
                     ans.push_back("B");
                        handleRotation("B");
                         ans.push_back("R");
                        handleRotation("R");
                         ans.push_back("D");
                        handleRotation("D");
                         ans.push_back("R'");
                        handleRotation("R'");
                         ans.push_back("D'");
                        handleRotation("D'");
                         ans.push_back("B'");
                        handleRotation("B'");
        }
        else if(pos_to_piece[9][2]=='D' && pos_to_piece[8][1]=='D' && pos_to_piece[18][1]=='D'){
            
                      ans.push_back("D'");
                        handleRotation("D'");
                     ans.push_back("B");
                        handleRotation("B");
                         ans.push_back("R");
                        handleRotation("R");
                         ans.push_back("D");
                        handleRotation("D");
                         ans.push_back("R'");
                        handleRotation("R'");
                         ans.push_back("D'");
                        handleRotation("D'");
                         ans.push_back("B'");
                        handleRotation("B'");
        }
        else if(pos_to_piece[16][1]=='D' && pos_to_piece[25][2]=='D' && pos_to_piece[26][1]=='D'){
             
                      ans.push_back("D");
                        handleRotation("D");
                     ans.push_back("B");
                        handleRotation("B");
                         ans.push_back("R");
                        handleRotation("R");
                         ans.push_back("D");
                        handleRotation("D");
                         ans.push_back("R'");
                        handleRotation("R'");
                         ans.push_back("D'");
                        handleRotation("D'");
                         ans.push_back("B'");
                        handleRotation("B'");
        }
        else if(pos_to_piece[26][1]=='D' && pos_to_piece[27][2]=='D' && pos_to_piece[18][1]=='D'){
                
                      ans.push_back("D2");
                        handleRotation("D2");
                     ans.push_back("B");
                        handleRotation("B");
                         ans.push_back("R");
                        handleRotation("R");
                         ans.push_back("D");
                        handleRotation("D");
                         ans.push_back("R'");
                        handleRotation("R'");
                         ans.push_back("D'");
                        handleRotation("D'");
                         ans.push_back("B'");
                        handleRotation("B'");
        }


        // POINT CASE 
       else {
         
                    ans.push_back("B");
                        handleRotation("B");
                         ans.push_back("R");
                        handleRotation("R");
                         ans.push_back("D");
                        handleRotation("D");
                         ans.push_back("R'");
                        handleRotation("R'");
                         ans.push_back("D'");
                        handleRotation("D'");
                         ans.push_back("B'");
                        handleRotation("B'");
        }

        


      






    }
  }



 void downLayerEdgeMatching(){


         while(1){
              if(pos_to_piece[8][0]=='F' && pos_to_piece[18][0]=='R' &&pos_to_piece[26][0]=='B' && pos_to_piece[16][0]=='L'){
                      break;
          }
          else if(pos_to_piece[18][0]=='F' && pos_to_piece[26][0]=='R' &&pos_to_piece[16][0]=='B' && pos_to_piece[8][0]=='L'){
                        ans.push_back("D'");
                        handleRotation("D'");
                      break;
          }
          else if(pos_to_piece[26][0]=='F' && pos_to_piece[16][0]=='R' &&pos_to_piece[8][0]=='B' && pos_to_piece[18][0]=='L'){
                        ans.push_back("D2");
                        handleRotation("D2");
                      break;
          }
          else if(pos_to_piece[16][0]=='F' && pos_to_piece[8][0]=='R' &&pos_to_piece[18][0]=='B' && pos_to_piece[26][0]=='L'){
                        ans.push_back("D");
                        handleRotation("D");
                      break;
          }


          //  FRONT RIGHT

           if(pos_to_piece[8][0]=='F' && pos_to_piece[18][0]=='R'){
                        ans.push_back("R");
                        handleRotation("R");
                         ans.push_back("D");
                        handleRotation("D");
                         ans.push_back("R'");
                        handleRotation("R'");
                         ans.push_back("D");
                        handleRotation("D");
                         ans.push_back("R");
                        handleRotation("R");
                         ans.push_back("D2");
                        handleRotation("D2");
                        ans.push_back("R'");
                        handleRotation("R'");
                        ans.push_back("D");
                        handleRotation("D");
          }
         else if(pos_to_piece[18][0]=='F' && pos_to_piece[26][0]=='R'){
                        ans.push_back("D'");
                        handleRotation("D'");
                        
          }
          else if(pos_to_piece[26][0]=='F' && pos_to_piece[16][0]=='R'){
                        ans.push_back("D2");
                        handleRotation("D2");
                        
          }
          else if(pos_to_piece[16][0]=='F' && pos_to_piece[8][0]=='R'){
                        ans.push_back("D");
                        handleRotation("D");
                        
          }


            //  RIGHT BACK

          else if(pos_to_piece[8][0]=='R' && pos_to_piece[18][0]=='B'){
                       
                         ans.push_back("D");
                        handleRotation("D");
                        
          }
         else if(pos_to_piece[18][0]=='R' && pos_to_piece[26][0]=='B'){
                        ans.push_back("B");
                        handleRotation("B");
                         ans.push_back("D");
                        handleRotation("D");
                         ans.push_back("B'");
                        handleRotation("B'");
                         ans.push_back("D");
                        handleRotation("D");
                         ans.push_back("B");
                        handleRotation("B");
                         ans.push_back("D2");
                        handleRotation("D2");
                        ans.push_back("B'");
                        handleRotation("B'");
                        ans.push_back("D");
                        handleRotation("D");
          }
          else if(pos_to_piece[26][0]=='R' && pos_to_piece[16][0]=='B'){
                        ans.push_back("D'");
                        handleRotation("D'");
                        
          }
          else if(pos_to_piece[16][0]=='R' && pos_to_piece[8][0]=='B'){
                        ans.push_back("D2");
                        handleRotation("D2");
                        
          }



           //   BACK LEFT

         else  if(pos_to_piece[8][0]=='B' && pos_to_piece[18][0]=='L'){
                       
                         ans.push_back("D2");
                        handleRotation("D2");
                        
          }
         else if(pos_to_piece[18][0]=='B' && pos_to_piece[26][0]=='L'){
                        ans.push_back("D");
                        handleRotation("D");
                        
          }
          else if(pos_to_piece[26][0]=='B' && pos_to_piece[16][0]=='L'){
                     ans.push_back("L");
                        handleRotation("L");
                         ans.push_back("D");
                        handleRotation("D");
                         ans.push_back("L'");
                        handleRotation("L'");
                         ans.push_back("D");
                        handleRotation("D");
                         ans.push_back("L");
                        handleRotation("L");
                         ans.push_back("D2");
                        handleRotation("D2");
                        ans.push_back("L'");
                        handleRotation("L'");
                        ans.push_back("D");
                        handleRotation("D");
                        
          }
          else if(pos_to_piece[16][0]=='B' && pos_to_piece[8][0]=='L'){
                        ans.push_back("D'");
                        handleRotation("D'");
                        
          }


           //  LEFT FRONT

         else if(pos_to_piece[8][0]=='L' && pos_to_piece[18][0]=='F'){
                       
                         ans.push_back("D'");
                        handleRotation("D'");
                        
          }
         else if(pos_to_piece[18][0]=='L' && pos_to_piece[26][0]=='F'){
                      
                         ans.push_back("D2");
                        handleRotation("D2");
                   
          }
          else if(pos_to_piece[26][0]=='L' && pos_to_piece[16][0]=='F'){
                        ans.push_back("D");
                        handleRotation("D");
                        
          }
          else if(pos_to_piece[16][0]=='L' && pos_to_piece[8][0]=='F'){
                       ans.push_back("F");
                        handleRotation("F");
                         ans.push_back("D");
                        handleRotation("D");
                         ans.push_back("F'");
                        handleRotation("F'");
                         ans.push_back("D");
                        handleRotation("D");
                         ans.push_back("F");
                        handleRotation("F");
                         ans.push_back("D2");
                        handleRotation("D2");
                        ans.push_back("F'");
                        handleRotation("F'");
                        ans.push_back("D");
                        handleRotation("D");
                        
          }


          else{
                 if(pos_to_piece[8][0]=='F' && pos_to_piece[8][1]=='D'){
                                 ans.push_back("L");
                        handleRotation("L");
                         ans.push_back("D");
                        handleRotation("D");
                         ans.push_back("L'");
                        handleRotation("L'");
                         ans.push_back("D");
                        handleRotation("D");
                         ans.push_back("L");
                        handleRotation("L");
                         ans.push_back("D2");
                        handleRotation("D2");
                        ans.push_back("L'");
                        handleRotation("L'");
                 }
                 else  if(pos_to_piece[18][0]=='F' && pos_to_piece[18][1]=='D'){
                                 ans.push_back("D'");
                        handleRotation("D'");
                 }
                 else  if(pos_to_piece[26][0]=='F' && pos_to_piece[26][1]=='D'){
                              ans.push_back("D2");
                        handleRotation("D2");
                 }
                 else  if(pos_to_piece[16][0]=='F' && pos_to_piece[16][1]=='D'){
                               ans.push_back("D");
                        handleRotation("D");
                 }
                 
          }

          




         }
   
         
 }



    void downLayerCornerPieces(){
             bool f=0;
          
                int cnt=0;
                if(piece_to_pos[{'F','D','R'}]==9 || piece_to_pos[{'F','R','D'}]==9 || piece_to_pos[{'D','F','R'}]==9 || piece_to_pos[{'D','R','F'}]==9 || piece_to_pos[{'R','F','D'}]==9 || piece_to_pos[{'R','D','F'}]==9){
                      cnt++;
                }
                if(piece_to_pos[{'B','D','R'}]==27 || piece_to_pos[{'B','R','D'}]==27 || piece_to_pos[{'D','B','R'}]==27 || piece_to_pos[{'D','R','B'}]==27 || piece_to_pos[{'R','B','D'}]==27 || piece_to_pos[{'R','D','B'}]==27){
                      cnt++;
                }
                if(piece_to_pos[{'B','D','L'}]==25 || piece_to_pos[{'B','L','D'}]==25 || piece_to_pos[{'D','B','L'}]==25 || piece_to_pos[{'D','L','B'}]==25 || piece_to_pos[{'L','B','D'}]==25 || piece_to_pos[{'L','D','B'}]==25){
                      cnt++;
                }
                if(piece_to_pos[{'F','D','L'}]==7 || piece_to_pos[{'F','L','D'}]==7 || piece_to_pos[{'D','F','L'}]==7 || piece_to_pos[{'D','L','F'}]==7 || piece_to_pos[{'L','F','D'}]==7 || piece_to_pos[{'L','D','F'}]==7){
                      cnt++;
                }


                  if(cnt==4){
                    return ;
                  }

                  int pos=-1;
                  while(1){
                        if(piece_to_pos[{'F','D','R'}]==9 || piece_to_pos[{'F','R','D'}]==9 || piece_to_pos[{'D','F','R'}]==9 || piece_to_pos[{'D','R','F'}]==9 || piece_to_pos[{'R','F','D'}]==9 || piece_to_pos[{'R','D','F'}]==9){
                      pos=9;
                      break;
                }
                if(piece_to_pos[{'B','D','R'}]==27 || piece_to_pos[{'B','R','D'}]==27 || piece_to_pos[{'D','B','R'}]==27 || piece_to_pos[{'D','R','B'}]==27 || piece_to_pos[{'R','B','D'}]==27 || piece_to_pos[{'R','D','B'}]==27){
                       pos=27;
                      break;
                }
                if(piece_to_pos[{'B','D','L'}]==25 || piece_to_pos[{'B','L','D'}]==25 || piece_to_pos[{'D','B','L'}]==25 || piece_to_pos[{'D','L','B'}]==25 || piece_to_pos[{'L','B','D'}]==25 || piece_to_pos[{'L','D','B'}]==25){
                       pos=25;
                      break;
                }
                if(piece_to_pos[{'F','D','L'}]==7 || piece_to_pos[{'F','L','D'}]==7 || piece_to_pos[{'D','F','L'}]==7 || piece_to_pos[{'D','L','F'}]==7 || piece_to_pos[{'L','F','D'}]==7 || piece_to_pos[{'L','D','F'}]==7){
                       pos=7;
                      break;
                }

                       ans.push_back("D");
                        handleRotation("D");
                        ans.push_back("F");
                        handleRotation("F");
                        
                         ans.push_back("D'");
                        handleRotation("D'");
                         ans.push_back("B'");
                        handleRotation("B'");
                         ans.push_back("D");
                        handleRotation("D");
                         ans.push_back("F'");
                        handleRotation("F'");
                        ans.push_back("D'");
                        handleRotation("D'");
                        ans.push_back("B");
                        handleRotation("B");
                             
                  }



                  if(pos==9){
                        while(1){
                             cnt=0;
                if(piece_to_pos[{'F','D','R'}]==9 || piece_to_pos[{'F','R','D'}]==9 || piece_to_pos[{'D','F','R'}]==9 || piece_to_pos[{'D','R','F'}]==9 || piece_to_pos[{'R','F','D'}]==9 || piece_to_pos[{'R','D','F'}]==9){
                      cnt++;
                }
                if(piece_to_pos[{'B','D','R'}]==27 || piece_to_pos[{'B','R','D'}]==27 || piece_to_pos[{'D','B','R'}]==27 || piece_to_pos[{'D','R','B'}]==27 || piece_to_pos[{'R','B','D'}]==27 || piece_to_pos[{'R','D','B'}]==27){
                      cnt++;
                }
                if(piece_to_pos[{'B','D','L'}]==25 || piece_to_pos[{'B','L','D'}]==25 || piece_to_pos[{'D','B','L'}]==25 || piece_to_pos[{'D','L','B'}]==25 || piece_to_pos[{'L','B','D'}]==25 || piece_to_pos[{'L','D','B'}]==25){
                    cnt++;
                }
                if(piece_to_pos[{'F','D','L'}]==7 || piece_to_pos[{'F','L','D'}]==7 || piece_to_pos[{'D','F','L'}]==7 || piece_to_pos[{'D','L','F'}]==7 || piece_to_pos[{'L','F','D'}]==7 || piece_to_pos[{'L','D','F'}]==7){
                      cnt++;
                }


                  if(cnt==4){
                    break; ;
                  }

                   ans.push_back("D");
                        handleRotation("D");
                        ans.push_back("F");
                        handleRotation("F");
                        
                         ans.push_back("D'");
                        handleRotation("D'");
                         ans.push_back("B'");
                        handleRotation("B'");
                         ans.push_back("D");
                        handleRotation("D");
                         ans.push_back("F'");
                        handleRotation("F'");
                        ans.push_back("D'");
                        handleRotation("D'");
                        ans.push_back("B");
                        handleRotation("B");


                        }
                  }



                  else if(pos==27){
                           while(1){
                             cnt=0;
                if(piece_to_pos[{'F','D','R'}]==9 || piece_to_pos[{'F','R','D'}]==9 || piece_to_pos[{'D','F','R'}]==9 || piece_to_pos[{'D','R','F'}]==9 || piece_to_pos[{'R','F','D'}]==9 || piece_to_pos[{'R','D','F'}]==9){
                      cnt++;
                }
                if(piece_to_pos[{'B','D','R'}]==27 || piece_to_pos[{'B','R','D'}]==27 || piece_to_pos[{'D','B','R'}]==27 || piece_to_pos[{'D','R','B'}]==27 || piece_to_pos[{'R','B','D'}]==27 || piece_to_pos[{'R','D','B'}]==27){
                      cnt++;
                }
                if(piece_to_pos[{'B','D','L'}]==25 || piece_to_pos[{'B','L','D'}]==25 || piece_to_pos[{'D','B','L'}]==25 || piece_to_pos[{'D','L','B'}]==25 || piece_to_pos[{'L','B','D'}]==25 || piece_to_pos[{'L','D','B'}]==25){
                    cnt++;
                }
                if(piece_to_pos[{'F','D','L'}]==7 || piece_to_pos[{'F','L','D'}]==7 || piece_to_pos[{'D','F','L'}]==7 || piece_to_pos[{'D','L','F'}]==7 || piece_to_pos[{'L','F','D'}]==7 || piece_to_pos[{'L','D','F'}]==7){
                      cnt++;
                }


                  if(cnt==4){
                    break; ;
                  }

                   ans.push_back("D");
                        handleRotation("D");
                        ans.push_back("R");
                        handleRotation("R");
                        
                         ans.push_back("D'");
                        handleRotation("D'");
                         ans.push_back("L'");
                        handleRotation("L'");
                         ans.push_back("D");
                        handleRotation("D");
                         ans.push_back("R'");
                        handleRotation("R'");
                        ans.push_back("D'");
                        handleRotation("D'");
                        ans.push_back("L");
                        handleRotation("L");


                        }
                  }
                  else if(pos==25){
                             while(1){
                             cnt=0;
                if(piece_to_pos[{'F','D','R'}]==9 || piece_to_pos[{'F','R','D'}]==9 || piece_to_pos[{'D','F','R'}]==9 || piece_to_pos[{'D','R','F'}]==9 || piece_to_pos[{'R','F','D'}]==9 || piece_to_pos[{'R','D','F'}]==9){
                      cnt++;
                }
                if(piece_to_pos[{'B','D','R'}]==27 || piece_to_pos[{'B','R','D'}]==27 || piece_to_pos[{'D','B','R'}]==27 || piece_to_pos[{'D','R','B'}]==27 || piece_to_pos[{'R','B','D'}]==27 || piece_to_pos[{'R','D','B'}]==27){
                      cnt++;
                }
                if(piece_to_pos[{'B','D','L'}]==25 || piece_to_pos[{'B','L','D'}]==25 || piece_to_pos[{'D','B','L'}]==25 || piece_to_pos[{'D','L','B'}]==25 || piece_to_pos[{'L','B','D'}]==25 || piece_to_pos[{'L','D','B'}]==25){
                    cnt++;
                }
                if(piece_to_pos[{'F','D','L'}]==7 || piece_to_pos[{'F','L','D'}]==7 || piece_to_pos[{'D','F','L'}]==7 || piece_to_pos[{'D','L','F'}]==7 || piece_to_pos[{'L','F','D'}]==7 || piece_to_pos[{'L','D','F'}]==7){
                      cnt++;
                }


                  if(cnt==4){
                    break; ;
                  }

                   ans.push_back("D");
                        handleRotation("D");
                        ans.push_back("B");
                        handleRotation("B");
                        
                         ans.push_back("D'");
                        handleRotation("D'");
                         ans.push_back("F'");
                        handleRotation("F'");
                         ans.push_back("D");
                        handleRotation("D");
                         ans.push_back("B'");
                        handleRotation("B'");
                        ans.push_back("D'");
                        handleRotation("D'");
                        ans.push_back("F");
                        handleRotation("F");


                        }
                  }
                  else if(pos==7){
                         while(1){
                             cnt=0;
                if(piece_to_pos[{'F','D','R'}]==9 || piece_to_pos[{'F','R','D'}]==9 || piece_to_pos[{'D','F','R'}]==9 || piece_to_pos[{'D','R','F'}]==9 || piece_to_pos[{'R','F','D'}]==9 || piece_to_pos[{'R','D','F'}]==9){
                      cnt++;
                }
                if(piece_to_pos[{'B','D','R'}]==27 || piece_to_pos[{'B','R','D'}]==27 || piece_to_pos[{'D','B','R'}]==27 || piece_to_pos[{'D','R','B'}]==27 || piece_to_pos[{'R','B','D'}]==27 || piece_to_pos[{'R','D','B'}]==27){
                      cnt++;
                }
                if(piece_to_pos[{'B','D','L'}]==25 || piece_to_pos[{'B','L','D'}]==25 || piece_to_pos[{'D','B','L'}]==25 || piece_to_pos[{'D','L','B'}]==25 || piece_to_pos[{'L','B','D'}]==25 || piece_to_pos[{'L','D','B'}]==25){
                    cnt++;
                }
                if(piece_to_pos[{'F','D','L'}]==7 || piece_to_pos[{'F','L','D'}]==7 || piece_to_pos[{'D','F','L'}]==7 || piece_to_pos[{'D','L','F'}]==7 || piece_to_pos[{'L','F','D'}]==7 || piece_to_pos[{'L','D','F'}]==7){
                      cnt++;
                }


                  if(cnt==4){
                    break; ;
                  }

                   ans.push_back("D");
                        handleRotation("D");
                        ans.push_back("L");
                        handleRotation("L");
                        
                         ans.push_back("D'");
                        handleRotation("D'");
                         ans.push_back("R'");
                        handleRotation("R'");
                         ans.push_back("D");
                        handleRotation("D");
                         ans.push_back("L'");
                        handleRotation("L'");
                        ans.push_back("D'");
                        handleRotation("D'");
                        ans.push_back("R");
                        handleRotation("R");


                        }
                  }
             
    }





    void finalMoves(){
             while(1){
                while(pos_to_piece[9][2]!='D'){
                            ans.push_back("R");
                        handleRotation("R");
                         ans.push_back("U");
                        handleRotation("U");
                        ans.push_back("R'");
                        handleRotation("R'");
                        ans.push_back("U'");
                        handleRotation("U'");
                }
                if(pos_to_piece[7][2]!='D'){
                        ans.push_back("D");
                        handleRotation("D");
                }
                else if(pos_to_piece[25][2]!='D'){
                        ans.push_back("D2");
                        handleRotation("D2");
                }
               else if(pos_to_piece[27][2]!='D'){
                        ans.push_back("D'");
                        handleRotation("D'");
                }
                else{
                    break;
                }
                
             }

            if(pos_to_piece[8][0]=='F'){
                return;
            }

            if(pos_to_piece[18][0]=='F'){
                ans.push_back("D'");
                        handleRotation("D'");
            }

            else if(pos_to_piece[26][0]=='F'){
                ans.push_back("D2");
                        handleRotation("D2");
            }
           else if(pos_to_piece[16][0]=='F'){
                ans.push_back("D");
                        handleRotation("D");
            }

            

    }



















int main(int argc, char** argv) {


    piece_to_pos.clear();
pos_to_piece.clear();
ans.clear();
indexToPos.clear();

    if (argc < 2) {
        cerr << "Need scramble string (or scramble split into argv parts)\n";
        return 1;
    }

    // Join all argv[1..] into a single string
   
    for (int i = 1; i < argc; ++i) scramble += argv[i];

   

    cerr << "DBG: got scramble len=" << scramble.size() << endl;
    if (scramble.size() != 54) {
        cerr << "ERR: scramble must be length 54, got " << scramble.size() << endl;
        return 1;
    }

       piece_to_pos[{scramble[6],scramble[18],scramble[38]}]=1;
       pos_to_piece[1]={scramble[6],scramble[18],scramble[38]};
       piece_to_pos[{scramble[19],scramble[7]}]=2;
       pos_to_piece[2]={scramble[19],scramble[7]};
       piece_to_pos[{scramble[8],scramble[20],scramble[9]}]=3;
       pos_to_piece[3]={scramble[8],scramble[20],scramble[9]};

       piece_to_pos[{scramble[21],scramble[41]}]=4;
       pos_to_piece[4]={scramble[21],scramble[41]};
       piece_to_pos[{scramble[23],scramble[12]}]=6;
       pos_to_piece[6]={scramble[23],scramble[12]};

       piece_to_pos[{scramble[24],scramble[44],scramble[27]}]=7;
       pos_to_piece[7]={scramble[24],scramble[44],scramble[27]};
       piece_to_pos[{scramble[25],scramble[28]}]=8;
       pos_to_piece[8]={scramble[25],scramble[28]};
       piece_to_pos[{scramble[26],scramble[15],scramble[29]}]=9;
       pos_to_piece[9]={scramble[26],scramble[15],scramble[29]};


    //    MIDDLE LAYER

       piece_to_pos[{scramble[3],scramble[37]}]=10;
       pos_to_piece[10]={scramble[3],scramble[37]};
       piece_to_pos[{scramble[5],scramble[10]}]=12;
       pos_to_piece[12]={scramble[5],scramble[10]};
      

       piece_to_pos[{scramble[43],scramble[30]}]=16;
       pos_to_piece[16]={scramble[43],scramble[30]};
       piece_to_pos[{scramble[16],scramble[32]}]=18;
       pos_to_piece[18]={scramble[16],scramble[32]};



    //   BACK LAYER 


     piece_to_pos[{scramble[0],scramble[36],scramble[47]}]=19;
       pos_to_piece[19]={scramble[0],scramble[36],scramble[47]};
       piece_to_pos[{scramble[1],scramble[46]}]=20;
       pos_to_piece[20]={scramble[1],scramble[46]};
       piece_to_pos[{scramble[2],scramble[11],scramble[45]}]=21;
       pos_to_piece[21]={scramble[2],scramble[11],scramble[45]};

       piece_to_pos[{scramble[39],scramble[50]}]=22;
       pos_to_piece[22]={scramble[39],scramble[50]};
       piece_to_pos[{scramble[14],scramble[48]}]=24;
       pos_to_piece[24]={scramble[14],scramble[48]};

       piece_to_pos[{scramble[42],scramble[53],scramble[33]}]=25;
       pos_to_piece[25]={scramble[42],scramble[53],scramble[33]};
       piece_to_pos[{scramble[52],scramble[34]}]=26;
       pos_to_piece[26]={scramble[52],scramble[34]};
       piece_to_pos[{scramble[17],scramble[51],scramble[35]}]=27;
       pos_to_piece[27]={scramble[17],scramble[51],scramble[35]};


       

    int idx = 1;
    for (int z = 1; z >=-1; --z) {
        for (int y = 1; y >= -1; --y) {
            for (int x = -1; x <= 1; ++x) {
                indexToPos[idx++] = { x, y, z };
            }
        }
    }

    // Solver phases
    cerr << "DBG: starting phases\n";
    cerr << "DBG: phase upper_Layer_Cross\n";
     cerr << "DBG: got scramble =" << scramble << endl;
    upper_Layer_Cross();
    cerr << "DBG: phase solvingCornersOfUpperFace\n";
    solvingCornersOfUpperFace();
    cerr << "DBG: phase secondLayer\n";
    secondLayer();
    cerr << "DBG: phase downCross\n";
    downCross();
    cerr << "DBG: phase downLayerEdgeMatching\n";
    downLayerEdgeMatching();
    cerr << "DBG: phase downLayerCornerPieces\n";
    downLayerCornerPieces();
    cerr << "DBG: phase finalMoves\n";
    finalMoves();

    // Output result
    cerr << "DBG: outputting ans, size=" << ans.size() << endl;
    for (size_t i = 0; i < ans.size(); i++) {
        cout << "\"" << ans[i] << "\"";
        if (i != ans.size() - 1) cout << ",";
    }
    cout << endl;

    cerr << "DBG: done successfully\n";
    return 0;
}






// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     string scramble;
//     cin >> scramble;

//     if (scramble.size() != 54) {
//         cerr << "ERR: scramble must be length 54, got " << scramble.size() << endl;
//         return 1;
//     }

//     // clear global state
//     piece_to_pos.clear();
//     pos_to_piece.clear();
//     ans.clear();
//     indexToPos.clear();
// cerr <<scramble<<endl;
//     // fill cube mapping ...
//     // (same as your existing mapping code)
//          piece_to_pos[{scramble[6],scramble[18],scramble[38]}]=1;
//        pos_to_piece[1]={scramble[6],scramble[18],scramble[38]};
//        piece_to_pos[{scramble[19],scramble[7]}]=2;
//        pos_to_piece[2]={scramble[19],scramble[7]};
//        piece_to_pos[{scramble[8],scramble[20],scramble[9]}]=3;
//        pos_to_piece[3]={scramble[8],scramble[20],scramble[9]};

//        piece_to_pos[{scramble[21],scramble[41]}]=4;
//        pos_to_piece[4]={scramble[21],scramble[41]};
//        piece_to_pos[{scramble[23],scramble[12]}]=6;
//        pos_to_piece[6]={scramble[23],scramble[12]};

//        piece_to_pos[{scramble[24],scramble[44],scramble[27]}]=7;
//        pos_to_piece[7]={scramble[24],scramble[44],scramble[27]};
//        piece_to_pos[{scramble[25],scramble[28]}]=8;
//        pos_to_piece[8]={scramble[25],scramble[28]};
//        piece_to_pos[{scramble[26],scramble[15],scramble[29]}]=9;
//        pos_to_piece[9]={scramble[26],scramble[15],scramble[29]};


//     //    MIDDLE LAYER

//        piece_to_pos[{scramble[3],scramble[37]}]=10;
//        pos_to_piece[10]={scramble[3],scramble[37]};
//        piece_to_pos[{scramble[5],scramble[10]}]=12;
//        pos_to_piece[12]={scramble[5],scramble[10]};
      

//        piece_to_pos[{scramble[43],scramble[30]}]=16;
//        pos_to_piece[16]={scramble[43],scramble[30]};
//        piece_to_pos[{scramble[16],scramble[32]}]=18;
//        pos_to_piece[18]={scramble[16],scramble[32]};



//     //   BACK LAYER 


//      piece_to_pos[{scramble[0],scramble[36],scramble[47]}]=19;
//        pos_to_piece[19]={scramble[0],scramble[36],scramble[47]};
//        piece_to_pos[{scramble[1],scramble[46]}]=20;
//        pos_to_piece[20]={scramble[1],scramble[46]};
//        piece_to_pos[{scramble[2],scramble[11],scramble[45]}]=21;
//        pos_to_piece[21]={scramble[2],scramble[11],scramble[45]};

//        piece_to_pos[{scramble[39],scramble[50]}]=22;
//        pos_to_piece[22]={scramble[39],scramble[50]};
//        piece_to_pos[{scramble[14],scramble[48]}]=24;
//        pos_to_piece[24]={scramble[14],scramble[48]};

//        piece_to_pos[{scramble[42],scramble[53],scramble[33]}]=25;
//        pos_to_piece[25]={scramble[42],scramble[53],scramble[33]};
//        piece_to_pos[{scramble[52],scramble[34]}]=26;
//        pos_to_piece[26]={scramble[52],scramble[34]};
//        piece_to_pos[{scramble[17],scramble[51],scramble[35]}]=27;
//        pos_to_piece[27]={scramble[17],scramble[51],scramble[35]};

//     // build index map
//     int idx = 1;
//     for (int z = 1; z >= -1; --z) {
//         for (int y = 1; y >= -1; --y) {
//             for (int x = -1; x <= 1; ++x) {
//                 indexToPos[idx++] = { x, y, z };
//             }
//         }
//     }

//     // solver
//     cerr << "DBG: phase downLayerEdgeMatching\n";
//     upper_Layer_Cross();
//     cerr << "DBG: phase downLayerEdgeMatching\n";
//     solvingCornersOfUpperFace();
//     secondLayer();
//     downCross();
//     downLayerEdgeMatching();
//     downLayerCornerPieces();
//     finalMoves();

//     // print result
//     for (size_t i = 0; i < ans.size(); i++) {
//         cout << "\"" << ans[i] << "\"";
//         if (i != ans.size() - 1) cout << ",";
//     }
//     cout << endl;
// }






// // assume piece_to_pos, pos_to_piece, indexToPos, ans, and solver functions are declared elsewhere

// int main(int argc, char** argv) {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     string scramble;
//     if (argc > 1) {
//         scramble = argv[1];
//     } else {
//         if (!(cin >> scramble)) {
//             cerr << "ERR: no input\n";
//             return 1;
//         }
//     }

//     // sanitize: keep only A-Z uppercase
//     string clean;
//     for (char c : scramble) if (c >= 'A' && c <= 'Z') clean.push_back(c);
//     scramble = clean;

//     if (scramble.size() != 54) {
//         cerr << "ERR: scramble must be 54 chars, got " << scramble.size() << "\n";
//         return 1;
//     }

//     // clear global state (important!)
//     piece_to_pos.clear();
//     pos_to_piece.clear();
//     ans.clear();
//     indexToPos.clear();

//     // DEBUG: (optional) show received scramble
//     // cerr << "DBG scramble=" << scramble << "\n";

//     // --- fill cube mapping (copy your existing mapping lines) ---
//     piece_to_pos[{scramble[6],scramble[18],scramble[38]}]=1;
//     pos_to_piece[1]={scramble[6],scramble[18],scramble[38]};
//     piece_to_pos[{scramble[19],scramble[7]}]=2;
//     pos_to_piece[2]={scramble[19],scramble[7]};
//     piece_to_pos[{scramble[8],scramble[20],scramble[9]}]=3;
//     pos_to_piece[3]={scramble[8],scramble[20],scramble[9]};

//     piece_to_pos[{scramble[21],scramble[41]}]=4;
//     pos_to_piece[4]={scramble[21],scramble[41]};
//     piece_to_pos[{scramble[23],scramble[12]}]=6;
//     pos_to_piece[6]={scramble[23],scramble[12]};

//     piece_to_pos[{scramble[24],scramble[44],scramble[27]}]=7;
//     pos_to_piece[7]={scramble[24],scramble[44],scramble[27]};
//     piece_to_pos[{scramble[25],scramble[28]}]=8;
//     pos_to_piece[8]={scramble[25],scramble[28]};
//     piece_to_pos[{scramble[26],scramble[15],scramble[29]}]=9;
//     pos_to_piece[9]={scramble[26],scramble[15],scramble[29]};

//     piece_to_pos[{scramble[3],scramble[37]}]=10;
//     pos_to_piece[10]={scramble[3],scramble[37]};
//     piece_to_pos[{scramble[5],scramble[10]}]=12;
//     pos_to_piece[12]={scramble[5],scramble[10]};

//     piece_to_pos[{scramble[43],scramble[30]}]=16;
//     pos_to_piece[16]={scramble[43],scramble[30]};
//     piece_to_pos[{scramble[16],scramble[32]}]=18;
//     pos_to_piece[18]={scramble[16],scramble[32]};

//     piece_to_pos[{scramble[0],scramble[36],scramble[47]}]=19;
//     pos_to_piece[19]={scramble[0],scramble[36],scramble[47]};
//     piece_to_pos[{scramble[1],scramble[46]}]=20;
//     pos_to_piece[20]={scramble[1],scramble[46]};
//     piece_to_pos[{scramble[2],scramble[11],scramble[45]}]=21;
//     pos_to_piece[21]={scramble[2],scramble[11],scramble[45]};

//     piece_to_pos[{scramble[39],scramble[50]}]=22;
//     pos_to_piece[22]={scramble[39],scramble[50]};
//     piece_to_pos[{scramble[14],scramble[48]}]=24;
//     pos_to_piece[24]={scramble[14],scramble[48]};

//     piece_to_pos[{scramble[42],scramble[53],scramble[33]}]=25;
//     pos_to_piece[25]={scramble[42],scramble[53],scramble[33]};
//     piece_to_pos[{scramble[52],scramble[34]}]=26;
//     pos_to_piece[26]={scramble[52],scramble[34]};
//     piece_to_pos[{scramble[17],scramble[51],scramble[35]}]=27;
//     pos_to_piece[27]={scramble[17],scramble[51],scramble[35]};

//     // index map
//     int idx = 1;
//     for (int z = 1; z >= -1; --z)
//         for (int y = 1; y >= -1; --y)
//             for (int x = -1; x <= 1; ++x)
//                 indexToPos[idx++] = { x, y, z };

//     // run solver phases
//     upper_Layer_Cross();
//     solvingCornersOfUpperFace();
//     secondLayer();
//     downCross();
//     downLayerEdgeMatching();
//     downLayerCornerPieces();
//     finalMoves();

//     // output (CSV style like before)
//     for (size_t i = 0; i < ans.size(); i++) {
//         cout << "\"" << ans[i] << "\"";
//         if (i + 1 < ans.size()) cout << ",";
//     }
//     cout << endl;
//     return 0;
// }





// int main(){
     
//        cin>>scramble;

//     //    FRONT LAYER

//        piece_to_pos[{scramble[6],scramble[18],scramble[38]}]=1;
//        pos_to_piece[1]={scramble[6],scramble[18],scramble[38]};
//        piece_to_pos[{scramble[19],scramble[7]}]=2;
//        pos_to_piece[2]={scramble[19],scramble[7]};
//        piece_to_pos[{scramble[8],scramble[20],scramble[9]}]=3;
//        pos_to_piece[3]={scramble[8],scramble[20],scramble[9]};

//        piece_to_pos[{scramble[21],scramble[41]}]=4;
//        pos_to_piece[4]={scramble[21],scramble[41]};
//        piece_to_pos[{scramble[23],scramble[12]}]=6;
//        pos_to_piece[6]={scramble[23],scramble[12]};

//        piece_to_pos[{scramble[24],scramble[44],scramble[27]}]=7;
//        pos_to_piece[7]={scramble[24],scramble[44],scramble[27]};
//        piece_to_pos[{scramble[25],scramble[28]}]=8;
//        pos_to_piece[8]={scramble[25],scramble[28]};
//        piece_to_pos[{scramble[26],scramble[15],scramble[29]}]=9;
//        pos_to_piece[9]={scramble[26],scramble[15],scramble[29]};


//     //    MIDDLE LAYER

//        piece_to_pos[{scramble[3],scramble[37]}]=10;
//        pos_to_piece[10]={scramble[3],scramble[37]};
//        piece_to_pos[{scramble[5],scramble[10]}]=12;
//        pos_to_piece[12]={scramble[5],scramble[10]};
      

//        piece_to_pos[{scramble[43],scramble[30]}]=16;
//        pos_to_piece[16]={scramble[43],scramble[30]};
//        piece_to_pos[{scramble[16],scramble[32]}]=18;
//        pos_to_piece[18]={scramble[16],scramble[32]};



//     //   BACK LAYER 


//      piece_to_pos[{scramble[0],scramble[36],scramble[47]}]=19;
//        pos_to_piece[19]={scramble[0],scramble[36],scramble[47]};
//        piece_to_pos[{scramble[1],scramble[46]}]=20;
//        pos_to_piece[20]={scramble[1],scramble[46]};
//        piece_to_pos[{scramble[2],scramble[11],scramble[45]}]=21;
//        pos_to_piece[21]={scramble[2],scramble[11],scramble[45]};

//        piece_to_pos[{scramble[39],scramble[50]}]=22;
//        pos_to_piece[22]={scramble[39],scramble[50]};
//        piece_to_pos[{scramble[14],scramble[48]}]=24;
//        pos_to_piece[24]={scramble[14],scramble[48]};

//        piece_to_pos[{scramble[42],scramble[53],scramble[33]}]=25;
//        pos_to_piece[25]={scramble[42],scramble[53],scramble[33]};
//        piece_to_pos[{scramble[52],scramble[34]}]=26;
//        pos_to_piece[26]={scramble[52],scramble[34]};
//        piece_to_pos[{scramble[17],scramble[51],scramble[35]}]=27;
//        pos_to_piece[27]={scramble[17],scramble[51],scramble[35]};


       

//     int idx = 1;
//     for (int z = 1; z >=-1; --z) {
//         for (int y = 1; y >= -1; --y) {
//             for (int x = -1; x <= 1; ++x) {
//                 indexToPos[idx++] = { x, y, z };
//             }
//         }
//     }

    
//     upper_Layer_Cross();
//     solvingCornersOfUpperFace();
//     secondLayer();
//     downCross();
//     downLayerEdgeMatching();
//     downLayerCornerPieces();
//     finalMoves();
    



    

// //     for(auto x:pos_to_piece){
// //            cout<<x.first<<"    ";
// //            for(int i=0;i<x.second.size();i++){
// //             cout<<x.second[i]<<" ";
// //            }

// //            cout<<endl;
// //     }

// //     cout<<endl;


// //     handleRotation("R'");


    

// //   for(auto x:pos_to_piece){
// //            cout<<x.first<<"    ";
// //            for(int i=0;i<x.second.size();i++){
// //             cout<<x.second[i]<<" ";
// //            }

// //            cout<<endl;
// //     }
    




// for(int i = 0; i < ans.size(); i++){
//     cout << "\"" << ans[i] << "\"";
//     if(i != ans.size() - 1) 
//         cout << ",";
// }






// }