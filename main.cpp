#include "shape.h"
#include "genetic.h"
#include <cstring>
#include <fstream>
#include <iostream>
#include <queue>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
#define POP_SIZE 100

int main() {
    srand((int)time(NULL));
    char input[21];
    char output[22];
    for(int i = 1;i<6;i++){
        if(i == 1){
            strcpy(input,"iccad2015_input.case1");
            strcpy(output,"iccad2015_output.case1");
        }
        else if(i == 2){
            strcpy(input,"iccad2015_input.case2");
            strcpy(output,"iccad2015_output.case2");
        }
        else if(i == 3){
            strcpy(input,"iccad2015_input.case3");
            strcpy(output,"iccad2015_output.case3");
        }
        else if(i == 4){
            strcpy(input,"iccad2015_input.case4");
            strcpy(output,"iccad2015_output.case4");
        }
        else if(i == 5){
            strcpy(input,"iccad2015_input.case5");
            strcpy(output,"iccad2015_output.case5");
        }
        else{

        }
        

        //char input[] = "testbench6.in";
        //char output[] = "testbench6.out";
        Coloring_Bounding_Box box = Coloring_Bounding_Box(input);
        /*
        for(int i = 0; i < 10;i++){
            Group *group = box.Groups[i];
            group->Color_shapes(CB);
            cout << group->id << endl; 
        }
        */

    	
        int length_gene = box.groups_num;
        

        //initialize chromosomes(the vector of chromo_typ)
        vector<chromo_typ> chromosomes;
        for(int i = 0;i<POP_SIZE;i++){
            chromo_typ chromo(length_gene,box);
            chromosomes.push_back(chromo);
        }
    	
        //initialize genome
        genome pop(chromosomes,box,length_gene,POP_SIZE);
        

     
        chromo_typ best_gene(length_gene,box);//Store the best gene
        
        //Run 10 times in case of being trapped in local maximum
        for(int i = 0; i< 5;i++){
            
            //The process of evolution
            for(int j = 0;j<10000;j++){
                pop.evolve();
                //cout << box.getScore() << endl;
            }
            
            //Find the best gene
            pop.GetBestGene().PrintChromo();
            if(pop.GetBestGene().Get_fitness()>best_gene.Get_fitness()){
                best_gene = pop.GetBestGene();
            }
        

        }
        box.color_all_groups(best_gene.output());
        box.write_file(output);


        cout << "The best gene is ";
        best_gene.PrintChromo();
        cout<<endl;
        cout << "The best score is " << best_gene.Get_fitness()<<endl;
    }
	return 0;
}
