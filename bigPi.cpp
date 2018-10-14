#include <iostream>
#include <iomanip>
#include <mpir.h>
#include <stdlib.h>
#include <string.h>
#include <cmath>
using namespace std;

const int MAX_ITERATIONS = 100;
const int PLACES         = 1000;        // desired decimal places
const int PRECISION      = PLACES + 1;  // +1 for the digit 3 before the decimal

//const int BASE       = 10;  // base 10 numbers
const int BIT_COUNT  = 8;   // bits per machine word

const int BLOCK_SIZE = 10;                // print digits in blocks
const int LINE_SIZE  = 100;               // digits to print per line
//const int LINE_COUNT = PLACES/LINE_SIZE;  // lines to print
const int GROUP_SIZE = 5;                 // line grouping size

void print(const mpf_t& pi);

/**
 * Compute the cube root of a positive integer.
 * @param x where to store the result.
 * @param a the number whose cube root to compute.
 */
void cube_root(mpf_t& x, const mpf_t a);
//void diff(mpf_t n, mpf_t mid,mpf_t& x);
/***** Add more functions as necessary. *****/

/**
 * The main.
 */
int main()
{
	/***** Complete this main. *****/
    mpf_set_default_prec(BIT_COUNT*PRECISION);   // precision in bits

    //declaring required variables
    mpf_t one_minus_rcube,s_start_value, u_n_plus_one, v_n_plus_one, s_n_plus_one, temp8,one_minus_scube,temp7;
    mpf_t one_sto, temp9,one_valstore, pi_value, temp10, r_n_plus_one, temp11, temp12, pow_val, val_nine_sto;
    mpf_t store_one, store_two, store_three, root_three, a_start_value, root_three_minus_one, r_start_value;
    mpf_t r_square, r_cube, value_one, value_two, temp1, t_n_plus_one, value_nine, nine_mul_r;
    mpf_t r_squ_val, one_plus_r_val, before_cube_root, t_squ_val, t_mul_u, w_n_plus_one,temp6;
    mpf_t u_squ_val, temp2, val_twenty_seven, one_plus_sval, sn_sq_val, numer_val, numer_by_den;
    mpf_t wn_mul_an, temp3, temp4, a_n_plus_one, one_min_r_val, one_minus_r_cube, two_times_u, temp5, deno_val;
    //initializing variables
	mpf_init(store_one);
    mpf_init(store_two);
	mpf_init(store_three);
	mpf_init(root_three);
	mpf_init(a_start_value);
	mpf_init(root_three_minus_one);
	mpf_init(r_start_value);
	mpf_init(r_square);
	mpf_init(r_cube);
	mpf_init(value_one);
	mpf_init(temp1);
	mpf_init(t_n_plus_one);
	mpf_init(value_nine);
	mpf_init(nine_mul_r);
	mpf_init(r_squ_val);
	mpf_init(one_plus_r_val);
	mpf_init(before_cube_root);
	mpf_init(t_squ_val);
	mpf_init(t_mul_u);
	mpf_init(u_squ_val);
	mpf_init(temp2);
	mpf_init(temp2);
	mpf_init(temp2);
	mpf_init(val_twenty_seven);
	mpf_init(one_plus_sval);
	mpf_init(sn_sq_val);
	mpf_init(numer_val);
	mpf_init(numer_by_den);
	mpf_init(w_n_plus_one);
	mpf_init(wn_mul_an);
	mpf_init(temp3);
	mpf_init(temp4);
	mpf_init(a_n_plus_one);
	mpf_init(one_min_r_val);
	mpf_init(one_minus_r_cube);
	mpf_init(two_times_u);
	mpf_init(temp5);
	mpf_init(deno_val);
	mpf_init(temp6);
	mpf_init(one_minus_scube);
	mpf_init(temp7);
	mpf_init(one_minus_rcube);
	mpf_init(s_start_value);
	mpf_init(u_n_plus_one);
	mpf_init(v_n_plus_one);
	mpf_init(s_n_plus_one);
	mpf_init(temp8);
	mpf_init(one_sto);
	mpf_init(temp9);
	mpf_init(one_valstore);
	mpf_init(pi_value);
	mpf_init(value_two);
	mpf_init(temp10);
	mpf_init(r_n_plus_one);
	mpf_init(temp11);
	mpf_init(temp12);
	mpf_init(pow_val);
	mpf_init(val_nine_sto);


	//compute a0
	mpf_set_ui(store_one,1);			  							//setting the value of store_one to 1.
	mpf_set_ui(store_two,2);			 							//setting store_two to 2
	mpf_set_ui(store_three,3);									 //setting store_three to 3
	mpf_div(a_start_value, store_one, store_three);         	//a0 =1/3 is stored in a_start_value

	mpf_sqrt(root_three,store_three);              				//root of 3 is stored in root_three
	mpf_sub_ui(root_three_minus_one,root_three,1); 		 		//root3-1 is stored in root_three_minus_one
	mpf_div_ui(r_start_value,root_three_minus_one,2);         	//r0 computed = root 3 - 1 /2

	//computing s0 = (1-r^3 )^1/3

	mpf_mul(r_square,r_start_value,r_start_value);				//r^2 computed
	mpf_mul(r_cube,r_square,r_start_value); 				 //r^3 computed in r_cube
	mpf_sub(one_minus_rcube,store_one,r_cube); 				//(1-r^3)
	cube_root(s_start_value,one_minus_rcube) ;	   		   //s0 computd and stored in s_start_value

	for(int i= 1 ; i <= MAX_ITERATIONS; i++)
	{
	if(i==1)
	{
		mpf_set(r_start_value,r_start_value);
		mpf_set(s_start_value,s_start_value);
		mpf_set(a_start_value,a_start_value);
	}
	if(i>1 && i<=100)
	{
		mpf_set(r_start_value,r_n_plus_one);    //update rn
		mpf_set(s_start_value,s_n_plus_one);	//update sn
		mpf_set(a_start_value,a_n_plus_one);	//update an
	}

//compute tn+1

	mpf_set_ui(value_one,1);
	mpf_set_ui(value_two,2);
	mpf_mul(temp1,r_start_value,value_two);						//2*rn computed
	mpf_add(t_n_plus_one,temp1,value_one); 						//tn+1 = 1+2rn computed =t_n_plus_one

//compute un+1
	mpf_set_ui(value_nine,9);
	mpf_mul(nine_mul_r,value_nine,r_start_value);  				// 9 * rn
	mpf_mul(r_squ_val,r_start_value,r_start_value);				//rn^2 in r_squ_val
	mpf_add_ui(one_plus_r_val,r_start_value,1);					//1+rn in one_plus_r_val
	mpf_add(one_plus_r_val,one_plus_r_val,r_squ_val); 			//1+rn+rn^2 ==one_plus_r_val
	mpf_mul(before_cube_root,one_plus_r_val,nine_mul_r);   		//9rn(1+rn+rn^2) in before_cube_root
	cube_root(u_n_plus_one,before_cube_root); 					//cube root of before_cube_root stored in u_n_plus_one		un+1 calculated

//compute vn+1
	mpf_mul(t_squ_val,t_n_plus_one,t_n_plus_one);  					//tn^2
	mpf_mul(t_mul_u,t_n_plus_one,u_n_plus_one); 					//(tn+1 * un+1) in t_mul_u
	mpf_mul(u_squ_val,u_n_plus_one,u_n_plus_one); 					//un+1 ^ 2 in u_squ_val
	mpf_add(temp2,t_squ_val,t_mul_u);								//tn+1 ^2 + tn+! * un+1
	mpf_add(v_n_plus_one,temp2,u_squ_val); 							//tn+1 ^2 + tn+1 *un+1 +un+1^2	  vn+1 is calculated

//compute wn+1
	mpf_set_ui(val_twenty_seven,27);
	mpf_add_ui(one_plus_sval,s_start_value,1); 						//1+sn
	mpf_mul(sn_sq_val,s_start_value,s_start_value); 				//sn^2
	mpf_add(numer_val,one_plus_sval,sn_sq_val); 					//1+sn+sn^2
	mpf_div(numer_by_den,numer_val,v_n_plus_one); 					//divided by vn+1
	mpf_mul(w_n_plus_one,numer_by_den,val_twenty_seven); 			// Multiplied by 27		 Wn+1 computed in w_n_plus_one


//compute an+1
	mpf_mul(wn_mul_an,w_n_plus_one,a_start_value);   			//wn+1 * an in wn_mul_an

	if(i==1)
	{
	mpf_set_ui(temp11,1);
	mpf_set_ui(temp12,3);
	mpf_div(pow_val,temp11,temp12);
	}
	if(i>1)
	{
		mpf_set_ui(val_nine_sto,9);
		mpf_mul(pow_val,pow_val,val_nine_sto);
	}
	mpf_set(temp10,pow_val); 								//1/3 is stord in temp10
	mpf_set_ui(one_sto,1);
	mpf_sub(temp3,one_sto,w_n_plus_one);  					//(1-wn+1) in temp3
	mpf_mul(temp4,temp3,temp10); 							//1-wn+1 * p
	mpf_add(a_n_plus_one,temp4,wn_mul_an); 					//an+1 computed in a_n_plus_one

//compute sn+1
	mpf_sub(one_min_r_val,one_sto,r_start_value);
	mpf_mul(one_minus_r_cube,one_min_r_val,one_min_r_val);
	mpf_mul(one_minus_r_cube,one_minus_r_cube,one_min_r_val); 					//(1-rn) ^3
	mpf_mul_ui(two_times_u,u_n_plus_one,2); 								//2un+1 computed
	mpf_add(temp5,t_n_plus_one,two_times_u); 								//(tn+1 + 2un+1) in temp5
	mpf_mul(deno_val,temp5,v_n_plus_one); 									//denominator (tn+1 + 2un+1) * vn+1
	mpf_div(s_n_plus_one,one_minus_r_cube,deno_val); 						//sn+1 computed in s_n_plus_one

//compute rn+1
	mpf_mul(temp6,s_n_plus_one,s_n_plus_one);
	mpf_mul(temp6,temp6,s_n_plus_one); 										//sn+1^3 computed
	mpf_sub(one_minus_scube,one_sto,temp6); 								//(1 - sn+1 ^3) computed
	cube_root(temp9,one_minus_scube); 										//rn+1 computed in temp9
	mpf_set(r_n_plus_one,temp9);

	}

mpf_set_ui(one_valstore,1);
mpf_div(pi_value,one_valstore,a_start_value);
print(pi_value);

return 0;
}

// Cube root using Halleys method
void cube_root(mpf_t& x, const mpf_t a)
{

	mpf_t v1, v2, v3, v4, v5, v6, v7, v8,v9, v10, v11, v12, xval;  		//declaring variaobles
	mpf_init(v1);														//initializing variables
	mpf_init(v2);
	mpf_init(v3);
	mpf_init(v4);
	mpf_init(v5);
	mpf_init(v6);
	mpf_init(v7);
	mpf_init(v8);
	mpf_init(v9);
	mpf_init(v10);
	mpf_init(v11);
	mpf_init(v12);
	mpf_init(xval);
	mpf_set_ui(v7,2);


	for(int i=0;i<10;i++)
	{
		if(i==0)
		{
			mpf_set_ui(xval,1); //xval = 1
		}
		else
		{
			mpf_set(xval,v8);
		}

		mpf_mul(v1,xval,xval);
		mpf_mul(v2,v1,xval); 		//x cube
		mpf_mul_ui(v3,a,2); 		//2a
		mpf_add(v4,v2,v3); 			//numerator
		mpf_mul_ui(v5,v2,2); 		//2x cube
		mpf_add(v6,v5,a); 			//denominator
		mpf_div(v7,v4,v6); 			//divide
		mpf_mul(v8,v7,xval);

	}

	mpf_set(x,v8);
}




void print(const mpf_t& pi_val)
{

long int store_one;  //store exponent as 1
int block_size;		//to convert constant block size as an variable integer
int group_size;		//convert constant group size as variable integer
int line_size;		//convert constant line size to variable integer
int precision_val;
char* null_str = NULL; //store null

	store_one = 1;
	char* str_pi = mpf_get_str(null_str,&store_one,10,1001,pi_val); //convert value of pi to a string of digits

	cout<<"\n";

	int i=0;
		while (i==0)
		{
		cout << *(str_pi + i); //prints first value of Pi which is 3
		cout<<"."; //prints a decimal point after 3
		break;
		}


	int j = 1;
//assigning constants to variables
	block_size = BLOCK_SIZE;
	line_size = LINE_SIZE;
	group_size = GROUP_SIZE;
	precision_val = PRECISION;
	while(j < precision_val)
	{
		cout<< *(str_pi+j);	 //print digits after decimal point
		line_size = line_size-1;
		block_size = block_size-1;

		while(block_size==0)   //put a space after each block of numbers
		{
			cout<<" ";
			block_size=BLOCK_SIZE;
			break;
		}

		while(line_size==0 ) //when number of digits in a line reaches hundred,go to next line
		{
			cout<<endl<<"  ";
			line_size=LINE_SIZE;
			group_size = group_size-1;
			while(group_size==0 )
			{
				cout<< endl;
				cout<<"  ";
				group_size=GROUP_SIZE;
				break;
			}

			break;
		}
		j++;
	}
}








