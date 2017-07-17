#include <fstream>
#include <iostream>
#include <boost/filesystem.hpp>

using namespace std;

string join2(string part1, string part2){
    part1.append(part2);
    return part1;
}
string join3(string part1, string part2, string part3){
    part1.append(part2);
    part1.append(part3);
    return part1;
}
string join4(string part1, string part2, string part3, string part4){
    part1.append(part2);
    part1.append(part3);
    part1.append(part4);
    return part1;
}

string prepath = "../anim_data/";

void mkdir(){
    string dirarr[10] = {"Coords_p","Coords_e","Ux_element","Uy_element","Ux_particle","Uy_particle","Sxx","Syy","Sxy","Phase_field"};


    for (int i=0;i<10;i++) {
        string path_str = prepath;
        path_str.append(dirarr[i]);
        const char* path = join2(prepath,dirarr[i]).c_str();
        boost::filesystem::path dir(path);
        if(boost::filesystem::create_directories(dir))
        {
            std::cout<< "Directory Created: "<<path<<std::endl;
        }
    }

}

void loadp(string file_num_str){
    //variable declarations
    string word;
    long int num=0;
    string out1, out2, out_dummy;
    string wordToFind[]= {"POINTS","Ux","Uy","Sxx","Syy","Sxy"};

    //open input file
    ifstream inpfile(join3("../Animation/Particles",file_num_str,".vtk"));

    if (inpfile.is_open()){
        //open output files
        ofstream coordf(join4(prepath,"Coords_p/coords_particle",file_num_str,".txt"));
        ofstream ux(join4(prepath,"Ux_particle/Ux",file_num_str,".txt"));
        ofstream uy(join4(prepath,"Uy_particle/Uy",file_num_str,".txt"));
        ofstream sxxf(join4(prepath,"Sxx/Sxx",file_num_str,".txt"));
        ofstream syyf(join4(prepath,"Syy/Syy",file_num_str,".txt"));
        ofstream sxyf(join4(prepath,"Sxy/Sxy",file_num_str,".txt"));
        while ( inpfile.good() )	{
            inpfile >> word;

            if (inpfile.good() && word.compare(wordToFind[0]) == 0) { //when it manage to find "POINTS"
                inpfile >> word; //get the next line(which is the number of points
                num = stoi(word);
                inpfile >> out_dummy;
                for (int i=0;i<num;i++){
                    inpfile >> out1 >> out2 >> out_dummy;
                    coordf << out1 << '\t' << out2 << endl;
                }
            }
            if (inpfile.good() && word.compare(wordToFind[1]) == 0) { //when it manage to find the "Sxx"
                inpfile >> out_dummy >> out_dummy >> out_dummy;
                for (int i=0;i<num;i++){
                    inpfile >> out1;
                    ux << out1 << endl;
                }
            }

            if (inpfile.good() && word.compare(wordToFind[2]) == 0) { //when it manage to find the "Syy"
                inpfile >> out_dummy >> out_dummy >> out_dummy;
                for (int i=0;i<num;i++){
                    inpfile >> out1;
                    uy << out1 << endl;
                }
            }

            if (inpfile.good() && word.compare(wordToFind[3]) == 0) { //when it manage to find the "Sxy"
                inpfile >> out_dummy >> out_dummy >> out_dummy;
                for (int i=0;i<num;i++){
                    inpfile >> out1;
                    sxxf << out1 << endl;
                }
            }

            if (inpfile.good() && word.compare(wordToFind[4]) == 0) { //when it manage to find the "Sxy"
                inpfile >> out_dummy >> out_dummy >> out_dummy;
                for (int i=0;i<num;i++){
                    inpfile >> out1;
                    syyf << out1 << endl;
                }
            }

            if (inpfile.good() && word.compare(wordToFind[5]) == 0) { //when it manage to find the "Sxy"
                inpfile >> out_dummy >> out_dummy >> out_dummy;
                for (int i=0;i<num;i++){
                    inpfile >> out1;
                    sxyf << out1 << endl;
                }
            }
        }
        inpfile.close();
        coordf.close();
        ux.close();
        uy.close();
        sxxf.close();
        syyf.close();
        sxyf.close();
        cout << "Particles" << file_num_str << ".vtk has been processed which has ";
        cout << num << " variables." << endl;
    }
    else
    {
        cout << "Unable to open file " << join3("Particles",file_num_str,".vtk") << endl;
    }
}

void loade(string file_num_str){
    string word;
    long int num=0;
    //variable declarations
    string out1, out2, out_dummy;
    string wordToFind[]= {"POINTS","Ux","Uy","Phase_Field"};

    //open input file
    ifstream inpfile(join3("../Animation/Elements",file_num_str,".vtk"));

    if (inpfile.is_open()){
        //open output files
        ofstream coordf(join4(prepath,"Coords_e/coords_element",file_num_str,".txt"));
        ofstream ux(join4(prepath,"Ux_element/Ux",file_num_str,".txt"));
        ofstream uy(join4(prepath,"Uy_element/Uy",file_num_str,".txt"));
        ofstream phase(join4(prepath,"Phase_field/Phase_field",file_num_str,".txt"));
        while ( inpfile.good() )	{
            inpfile >> word;

            if (inpfile.good() && word.compare(wordToFind[0]) == 0) { //when it manage to find "POINTS"
                inpfile >> word; //get the next line(which is the number of points
                num = stoi(word);
                inpfile >> out_dummy;
                for (int i=0;i<num;i++){
                    inpfile >> out1 >> out2 >> out_dummy;
                    coordf << out1 << '\t' << out2 << endl;
                }
            }
            if (inpfile.good() && word.compare(wordToFind[1]) == 0) { //when it manage to find the "Ux"
                inpfile >> out_dummy >> out_dummy >> out_dummy;
                for (int i=0;i<num;i++){
                    inpfile >> out1;
                    ux << out1 << endl;
                }
            }

            if (inpfile.good() && word.compare(wordToFind[2]) == 0) { //when it manage to find the "Uy"
                inpfile >> out_dummy >> out_dummy >> out_dummy;
                for (int i=0;i<num;i++){
                    inpfile >> out1;
                    uy << out1 << endl;
                }
            }

            if (inpfile.good() && word.compare(wordToFind[3]) == 0) { //when it manage to find the "Phase_Field"
                inpfile >> out_dummy >> out_dummy >> out_dummy;
                for (int i=0;i<num;i++){
                    inpfile >> out1;
                    phase << out1 << endl;
                }
            }
        }
        inpfile.close();
        coordf.close();
        ux.close();
        uy.close();
        phase.close();
        cout << "Elements" << file_num_str << ".vtk has been processed which has ";
        cout << num << " variables." << endl;
    }
    else
    {
        cout << "Unable to open file " << join3("Elements",file_num_str,".vtk") << endl;
    }
}

int main(int argc, char** argv){
    clock_t start;
    start = clock();
    mkdir();
    if(argc > 1){
#pragma omp parallel num_threads(4)
        {
#pragma omp for
            for(int i=1;i<argc;i++){
                loadp(argv[i]);
                loade(argv[i]);
            }
        }
    }



    /*
    #pragma omp parallel num_threads(8)
    {
        #pragma omp for
        for(int i=1;i<=100;i++){
            string file_num_str =to_string(i*10);
            loadp(file_num_str);

        }
    }
    */
    cout << endl << "Time elapsed: " << (clock()-start)/(CLOCKS_PER_SEC/1000) << "ms";
    return 0;

}