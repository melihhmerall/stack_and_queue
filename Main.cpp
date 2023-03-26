#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>


class stack {


public:
    std::string stak[100];
    int pos;
    stack() {
        pos = -1;
    }

    void push(std::string s) {
        pos++;
        stak[pos] = s;
    }

    void pop() {
        std::string show = stak[pos];
        stak[pos] = "";
        pos--;
    }
    void display(std::ofstream& myfile){
//        if (pos==0){
//            myfile<< stak[0];
//        } else{
        for (int i = 0; i <pos+1 ; ++i) {
            if (i ==pos){
                myfile<< stak[i];
            } else{
            myfile<< stak[i]<<",";}
        }
//        myfile<< stak[stak->size()];
//        }
        myfile << std::endl;
    }
    std::string last_element(){
        return stak[pos];
    }
    void posTo0(){
        for (int i = 0; i < pos+1; ++i) {
            stak[i] = "";
        }
        pos =-1;
    }


};
int main(int argc, char* argv[]) {
    std::vector<std::string> vectors;
    std::vector<std::string> T_vectors;
    std::vector<std::string> Q_vectors;
    std::vector<std::string> input_vectors;
    std::vector<std::string> inputcontrol_vectors;
    std::vector<std::string> accepter;
    std::vector<std::string> control_vector;
    std::vector<std::string> control_vector2;
    std::vector<std::string> output_vector;
    std::string input_tester;
    stack st;
    stack rj;
    char first_control;
    char second_control;
    char input;
    for (int i = 0; i < argc; ++i) {

        std::ifstream input1 (argv[1], std::ios::in);
        std::string line;

        while (getline(input1, line)) {

            vectors.push_back(line);

        }
        input1.close();
    }
    for (int i = 0; i < argc; ++i) {

        std::ifstream input2 (argv[2], std::ios::in);
        std::string line2;
        while (getline(input2, line2)) {
            if (line2==""){
                continue;
            } else{
            input_vectors.push_back(line2);}

        }
        input2.close();
    }
    std::ofstream myfile;
    myfile.open(argv[3]);
    for (int i = 0; i < vectors.size()/4; ++i) {
        if (vectors[i][0] == 'T'){
            T_vectors.push_back(vectors[i]);
        }else if (vectors[i][0] == 'Q'){
            control_vector.push_back(vectors[i]);
            Q_vectors.push_back(vectors[i]);
        } else if (vectors[i][0] == 'A'){
            control_vector.push_back(vectors[i]);
        } else if (vectors[i][0] == 'Z'){
            control_vector.push_back(vectors[i]);
        }
    }

    for (int i = 0; i < Q_vectors[0].size(); ++i) {
        if (Q_vectors[0][i] == '('){
            first_control =Q_vectors[0][i+1] ;
            second_control = Q_vectors[0][i+2];
        }
    }


    int meral =0;
    std::vector<std::string>::iterator i1;
    for (int i = 0; i < T_vectors.size(); ++i) {
        for (int j = 0; j < T_vectors[i].size(); ++j) {
            char melih = T_vectors[i][j];
            for (int k = 0; k < control_vector.size(); ++k) {
            if (!std::count(control_vector[0].begin(), control_vector[0].end(), melih)&& !std::count(control_vector[1].begin(), control_vector[1].end(), melih)&&!std::count(control_vector[2].begin(), control_vector[2].end(), melih)
            && melih!= 'e'&& melih!='T') {
                meral++;

            } else {

            }
            }

        }
    }

    if (meral==0) {


        for (int k = 0; k < input_vectors.size() / 4; ++k) {
            st.posTo0();
            rj.posTo0();
            int counter = 0;
            int controler = 0;
            int counter2 = 0;
            int accepter_counter = -1;
            int rejecter_counter = -1;

            accepter.clear();
            std::vector<std::string> rejecter;
            if (k == 0 || k == 3 || k == 6) {
                for (int i = 0; i < T_vectors.size(); ++i) {
                    if (T_vectors[i][2] == first_control && T_vectors[i][3] == second_control &&
                        counter2 < input_vectors[k].size()) {

                        if (input_vectors[k][counter] == T_vectors[i][5]) {
                            counter = counter + 2;
                            accepter_counter++;
                            accepter.push_back(T_vectors[i]);
                            myfile << T_vectors[i][2] << T_vectors[i][3] << T_vectors[i][4] << T_vectors[i][5]
                                   << T_vectors[i][6] << T_vectors[i][7]
                                   << " => " << T_vectors[i][9] << T_vectors[i][10] << T_vectors[i][11]
                                   << T_vectors[i][12]
                                   << " [STACK]:";
                            if (T_vectors[i][7] == 'e' && T_vectors[i][12] != 'e') {
                                std::string s(1, T_vectors[i][12]);
                                st.push(s);
                            } else if (T_vectors[i][12] == 'e') {
                                std::string s(1, T_vectors[i][7]);
                                if (st.last_element() == s) {
                                    st.pop();
                                }
                            }
                            st.display(myfile);
                            i = 0;
                        } else if (T_vectors[i][5] == 'e') {
                            accepter_counter++;
                            accepter.push_back(T_vectors[i]);
                            myfile << T_vectors[i][2] << T_vectors[i][3] << T_vectors[i][4] << T_vectors[i][5]
                                   << T_vectors[i][6] << T_vectors[i][7]
                                   << " => " << T_vectors[i][9] << T_vectors[i][10] << T_vectors[i][11]
                                   << T_vectors[i][12]
                                   << " [STACK]:";
                            if (T_vectors[i][7] == 'e' && T_vectors[i][12] != 'e') {
                                std::string s(1, T_vectors[i][12]);

                                st.push(s);

                            } else if (T_vectors[i][12] == 'e') {
                                std::string s(1, T_vectors[i][7]);
                                if (st.last_element() == s) {
                                    st.pop();
                                }
                            }
                            st.display(myfile);
                            i = 0;
                        }

                    } else if (T_vectors[i][2] == accepter[accepter_counter][9] &&
                               T_vectors[i][3] == accepter[accepter_counter][10]) {
                        if (T_vectors[i][5] == 'e') {
                            accepter_counter++;
                            accepter.push_back(T_vectors[i]);
                            myfile << T_vectors[i][2] << T_vectors[i][3] << T_vectors[i][4] << T_vectors[i][5]
                                   << T_vectors[i][6] << T_vectors[i][7]
                                   << " => " << T_vectors[i][9] << T_vectors[i][10] << T_vectors[i][11]
                                   << T_vectors[i][12]
                                   << " [STACK]:";
                            if (T_vectors[i][7] == 'e' && T_vectors[i][12] != 'e') {
                                std::string s(1, T_vectors[i][12]);

                                st.push(s);

                            } else if (T_vectors[i][12] == 'e') {
                                std::string s(1, T_vectors[i][7]);
                                if (st.last_element() == s) {
                                    st.pop();
                                }
                            }
                            st.display(myfile);
                            i = 0;
                        } else if (T_vectors[i][5] == input_vectors[k][counter] && counter < input_vectors[k].size()) {
                            accepter_counter++;
                            accepter.push_back(T_vectors[i]);
                            myfile << T_vectors[i][2] << T_vectors[i][3] << T_vectors[i][4] << T_vectors[i][5]
                                   << T_vectors[i][6] << T_vectors[i][7]
                                   << " => " << T_vectors[i][9] << T_vectors[i][10] << T_vectors[i][11]
                                   << T_vectors[i][12]
                                   << " [STACK]:";
                            counter = counter + 2;
                            if (T_vectors[i][7] == 'e' && T_vectors[i][12] != 'e') {
                                std::string s(1, T_vectors[i][12]);
                                st.push(s);

                            } else if (T_vectors[i][12] == 'e') {
                                std::string s(1, T_vectors[i][7]);
                                if (st.last_element() == s) {
                                    st.pop();
                                }
                            }
                            st.display(myfile);
                            i = 0;
                        }
                    } else {
                        continue;
                    }
                }
                myfile << "ACCEPT" << std::endl;
                myfile << "      " << std::endl;
            } else if (k == 1 || k == 4 || k == 7) {
                for (int i = 0; i < T_vectors.size(); ++i) {
                    if (T_vectors[i][2] == first_control && T_vectors[i][3] == second_control) {
                        if (input_vectors[k][counter2] == T_vectors[i][5] && counter2 < input_vectors[k].size()) {
                            rejecter_counter++;
                            myfile << T_vectors[i][2] << T_vectors[i][3] << T_vectors[i][4] << T_vectors[i][5]
                                   << T_vectors[i][6] << T_vectors[i][7]
                                   << " => " << T_vectors[i][9] << T_vectors[i][10] << T_vectors[i][11]
                                   << T_vectors[i][12]
                                   << " [STACK]:";
                            rejecter.push_back(T_vectors[i]);
                            counter2 = counter2 + 2;
                            if (T_vectors[i][7] == 'e' && T_vectors[i][12] != 'e') {
                                std::string s(1, T_vectors[i][12]);

                                rj.push(s);
                            } else if (T_vectors[i][12] == 'e') {

                                std::string s(1, T_vectors[i][7]);
                                if (rj.last_element() == s) {
                                    rj.pop();

                                }
                            }
                            rj.display(myfile);
                            i = 0;
                        } else if (T_vectors[i][5] == 'e' && controler == 0) {
                            myfile << T_vectors[i][2] << T_vectors[i][3] << T_vectors[i][4] << T_vectors[i][5]
                                   << T_vectors[i][6] << T_vectors[i][7]
                                   << " => " << T_vectors[i][9] << T_vectors[i][10] << T_vectors[i][11]
                                   << T_vectors[i][12]
                                   << " [STACK]:";
                            if (counter2 >= input_vectors[k].size()) {
                                controler++;
                            }
                            if (T_vectors[i][7] == 'e' && T_vectors[i][12] != 'e') {
                                std::string s(1, T_vectors[i][12]);
                                rj.push(s);
                            } else if (T_vectors[i][12] == 'e') {

                                std::string s(1, T_vectors[i][7]);
                                if (rj.last_element() == s) {
                                    rj.pop();

                                }
                            }
                            rj.display(myfile);
                            rejecter_counter++;
                            rejecter.push_back(T_vectors[i]);
                            i = 0;
                        }
                    } else if (T_vectors[i][2] == rejecter[rejecter_counter][9] &&
                               T_vectors[i][3] == rejecter[rejecter_counter][10]) {
                        if (T_vectors[i][5] == 'e' && controler == 0) {
                            if (counter2 >= input_vectors[k].size()) {
                                controler++;
                            }
                            rejecter_counter++;
                            rejecter.push_back(T_vectors[i]);
                            myfile << T_vectors[i][2] << T_vectors[i][3] << T_vectors[i][4] << T_vectors[i][5]
                                   << T_vectors[i][6] << T_vectors[i][7]
                                   << " => " << T_vectors[i][9] << T_vectors[i][10] << T_vectors[i][11]
                                   << T_vectors[i][12]
                                   << " [STACK]:";
                            if (T_vectors[i][7] == 'e' && T_vectors[i][12] != 'e') {
                                std::string s(1, T_vectors[i][12]);
                                rj.push(s);
                            } else if (T_vectors[i][12] == 'e') {
                                std::string s(1, T_vectors[i][7]);

                                if (rj.last_element() == s) {
                                    rj.pop();

                                }
                            }
                            rj.display(myfile);
                            i = 0;
                        } else if (T_vectors[i][5] == input_vectors[k][counter2] &&
                                   counter2 < input_vectors[k].size()) {
                            rejecter_counter++;
                            rejecter.push_back(T_vectors[i]);
                            myfile << T_vectors[i][2] << T_vectors[i][3] << T_vectors[i][4] << T_vectors[i][5]
                                   << T_vectors[i][6] << T_vectors[i][7]
                                   << " => " << T_vectors[i][9] << T_vectors[i][10] << T_vectors[i][11]
                                   << T_vectors[i][12]
                                   << " [STACK]:";
                            counter2 = counter2 + 2;
                            if (T_vectors[i][7] == 'e' && T_vectors[i][12] != 'e') {
                                std::string s(1, T_vectors[i][12]);
                                rj.push(s);
                            } else if (T_vectors[i][12] == 'e') {

                                std::string s(1, T_vectors[i][7]);
                                if (rj.last_element() == s) {

                                    rj.pop();
                                }
                            }
                            rj.display(myfile);
                            i = 0;
                        }
                    } else {
                        continue;
                    }
                }
                myfile << "REJECT" << std::endl;
                myfile << "      " << std::endl;
            }
        }
    } else{
        myfile << "Error [1]:DPDA description is invalid!";

    }


    return 0;
}
