
// #define t_alpha 6  //replaces all mentions of t_alpha with the number 6 at compile time, not going to use for no


int N;
double deg_total, deg_half, lower, upper, tf;
bool condA, condB;

const double  t_al = 1, t_del = 1, alpha = 2; // to be changed from results of other members
 

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Serial.println("    Enter in the desired angular displacement.");

readserial;
deg_half  = deg_total /2;
quickOpt;
}

void loop() {
  // put your main code here, to run repeatedly:
}

void readserial(){
        int a;
        if (Serial.available() > 0) {
                // read the incoming byte:
                a = Serial.parseInt(); // this takes the int and includes even negatives

                // say what you got:
                Serial.print("I received: ");
                Serial.println(a);
                deg_total = a;
        }
}
  

void quickOpt(){

   N =0; lower = 0; upper = 0;
   condA = false; condB = false;

   double accelRampLow=0, accelFLatLow=0, delaysLow=0,accelRampUp=0, accelFLatUp=0, delaysUp=0;

   while (condA ==false || condB = false){

      N++;


      // LOWER MARKER

      for (n=1; n<=N; n++){    //writing in a for loop instead of multipling for easier use of later conversion to multivariable
          
          accelRampLow = accelRampLow + (1/2) * alpha *  pow(t_al,2) 
      }
      
      for (n=1; n<=N-1; n++){    //writing in a for loop instead of multipling for easier use of later conversion to multivariable
          
          accelFLatLow = accelFLatLow + n * alpha * pow(t_al,2);     
          delaysLow = delaysLow + n * alpha * t_del*t_al ; 
      }

          // pure lower and upper not based on forced delays
      
      lower =  accelRampLow  + accelFLatLow + delaysLow +  1/2 * N * alpha * t_al* t_del;
     

      // UPPER MARKER
      for (n=1; n<=N+1; n++){    //writing in a for loop instead of multipling for easier use of later conversion to multivariable
          
          accelRampUp = accelRampUp + (1/2) * alpha *  pow(t_al,2)       
      }

      for (n=1; n<=N; n++){    //writing in a for loop instead of multipling for easier use of later conversion to multivariable
          
          accelFLatUp = accelFLatUp + n * alpha * pow(t_al,2); 
          delaysUp = delaysUp + n * alpha * t_del*t_al ;      
      }

       
      upper =  accelRampUp  + accelFLatUp + delaysUp +  1/2 * (N+1) * alpha * t_al* t_del;


      if(lower <=deg_half){
        condA = true;
      else
         condA = false;
         N= N-5; // forcing an N  jump down to lower the minimum
      }

      if (upper> deg_half)
         condB = true;
      else
          condB = false;

      
   }

    int diff = deg_half;

    diff = diff - lower;

    tf = diff *2 / alpha / t_al / N;


   
}

