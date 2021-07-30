#include<stdio.h>
#include<math.h>
void diffraction_grating();//function declarations
void numerical_aperture();
void energy_gap();
/*void newtons_rings();*/
void main()
{
    int ch;
    printf(" \t\t                    NITTE MEENAKSHI INSTITUTE OF TECHNOLGY\n");
    printf(" \t\t             DEPARTMENT OF INFORMATION SCIENCE AND ENGINNERING\n");
    printf(" \t\t                           DEPARTMENT OF PHYSICS\n\n");
    printf(" \t\t                 ENGINEERING PHYSICS LABORATORY MANUAL WITH C\n\n\n");
    printf("LIST OF EXPERIMENTS FOR THE SEMESTER :\n\n");
    printf("Enter '1' for 'DIFFRACTION GRATING'\nEnter '2' for 'NUMERICAL APERTURE'\n");
    printf("Enter '3' for 'ENERGY GAP OF A THERMISTOR'\nEnter '4' for 'NEWTONS RINGS'\n");
    printf("Enter '5' for ''\n\n");
    printf("Enter the choice of experiment you want to perform\n");
    scanf("%d",&ch);
    switch (ch)
    {
    case 1 :
        {
            printf("\t\t\t\t\t   'DIFFRACTION GRATING'\n");
            diffraction_grating();
            break;
        }
    case 2 :
        {
            printf("\t\t\t\t\t   'NUMERICAL APERTURE'\n");
            numerical_aperture();
            break;
        }
    case 3 :
        {
            printf("\t\t\t\t\t'ENERGY GAP OF THERMISTOR'\n");
            energy_gap();
            break;
        }
    case 4 :
        {
            printf("\t\t\t\t\t      'NEWTONS RINGS\n");
            /*newtons_rings();*/
            break;
        }
    case 5 :
        {
            printf("\t\t\t\t\t''\n");
            break;
        }
    default :
        {
            printf("WRONG CHOICE HAD ENTERED\n");
            break;
        }
    }
    printf("\n\n\t\t\t\t\t\t<<<----THE END--->>>\n\n");
    printf("THANK YOU\n\n");
    printf("PRESENTED BY :-\n");
    printf("ABHISHEK ANAND  \t1NT18IS006\tISE-A\n");
    printf("ABHISHEK SINGH  \t1NT18IS009\tISE-A\n");
    printf("ALOK KUMAR SINGH\t1NT18IS025\tISE-A\n");
    printf("GARVIT TANWAR   \t1NT18IS060\tISE-A\n");
}
void  diffraction_grating()//function body
{
 int i,n=1,N,vsd[5];//declaring necessary variables
 float lc=0,r=0,S,dmsr,msr[5],dvsd;//variables according to requirements
 double gc=0,tr[5],amd[5],lmd[5];//variables
 printf("\n\nAIM : TO DETERMINE THE GRATING CONSTANT AND WAVELENGTH OF DIFFERENT SPECTRAL LINES USING DIFFRATION\n\n");
 printf("APPARATUS : SPECTROMETER ,GRATING, MERCURY LAMP \n\n");//apparatus required
 printf("FORMULA : Wavelenght = 2Csin(D/2)\n");//formula required
 printf("                       ----------\n");
 printf("                            n    \n");
 printf("          where ,  C = grating constant\n");
 printf("                   D = angle of deviation\n");
 printf("                   n = order of the spectrum\n");
 printf("\nEnter the value of 1 main scale divisions:\t");//enter msd values
 scanf("%f",&S);
 printf("\nTotal no. of verniers scale divisions:\t");//enter vsd values
 scanf("%d",&N);
  lc=(S*3.142857)/(N*180);//calculating least count IN RADIAN
 printf("\nLEAST COUNT: %f\n\n",lc);//printing least count
 printf("Enter the 'MSR' and 'VSD' value for direct reading:\n");//asking user to enter (msr) to (vsd)
 scanf("%f%f",&dmsr,&dvsd);//DIRECT READING (WHITE LIGHT)
  r=((dmsr*3.14)/180)+(lc*dvsd);//ANGLE OF MINIMUM DEVIATION OF DIRECT READING
 printf("ANGLE OF MINIMUM DEVIATION FOR WHITE LIGHT(direct reading):\t%f\n\n",r);//printing value of angle of minimum deviation
 printf("'msd' and 'vsd' value for violet:\n");//VIOLET LIGHT
 scanf("%f%d",&msr[0],&vsd[0]);
 printf("\n'msd' and 'vsd' value for blue:\n");//BLUE LIGHT
 scanf("%f%d",&msr[1],&vsd[1]);
 printf("\n'msd' and 'vsd' value for green:\n");//GREEN LIGHT
 scanf("%f%d",&msr[2],&vsd[2]);
 printf("\n'msd' and 'vsd' value for yellow1:\n");//YELLOW 1 LIGHT
 scanf("%f%d",&msr[3],&vsd[3]);
 printf("\n'msd' and 'vsd' value for yellow2:\n");//YELLOW 2 LIGHT
 scanf("%f%d",&msr[4],&vsd[4]);
 for(i=0;i<5;i++)//LOOP FOR CALCULATING TOTAL READING AND ANGLE OF MINIMUM DEVIATION
 {
   tr[i]=0;
   amd[i]=0;
   tr[i]=((msr[i]*3.14)/180)+(vsd[i]*lc);//CALCULATING TOTAL READING
   amd[i]=tr[i]-r;//ANGLE OF MINIMUM DEVIATION
 }
 printf("\n\nTO FIND C :    C =        WAVELENTGH OF GREEN LIGHT\n");//formula to calculate C
 printf("                    --------------------------------------\n");
 printf("                    2*sin(0.5*angle of min dev.green light \n");
 gc=5461/(2*sin(amd[2]/2));//CALCULATING GRATING CONSTANT VALUE
 printf("\nVALUE OF GRATING CONSTANT : %f ANGSTROM\n",gc);//printing value for grating constant
 for(i=0;i<5;i++)//LOOP FOR CALCULATING WAVELENGTH
 {
   lmd[i]=(2*gc*sin(amd[i]/2))/n;//CALCULATING WAVELENGTH
 }
 printf("\n\nOBSERVATION TABLE:\n\n");//OBSERVATION
 printf("SPECTRAL LINES\tSPECTROMETER   READING\t\tANGLE OF MINIMUM DEVIATION    WAVENGTH \n");
 printf("              \tMSR       VSD      TR\t\t        (in radian)          (angstrom)\n");
 printf("  VIOLET      \t%f  %d  %f   \t\t%f\t      %f\n",msr[0],vsd[0],tr[0],amd[0],lmd[0]);//FOR VIOLET
 printf("  BLUE        \t%f  %d  %f   \t\t%f\t      %f\n",msr[1],vsd[1],tr[1],amd[1],lmd[1]);//FOR BLUE
 printf("  GREEN       \t%f  %d  %f   \t\t%f\t      %f\n",msr[2],vsd[2],tr[2],amd[2],lmd[2]);//FOR GREEN
 printf("  YELLOW 1    \t%f  %d  %f   \t\t%f\t      %f\n",msr[3],vsd[3],tr[3],amd[3],lmd[3]);//FOR YELLOW 1
 printf("  YELLOW 2    \t%f  %d  %f   \t\t%f\t      %f\n",msr[4],vsd[4],tr[4],amd[4],lmd[4]);//FOR YELLOW 2
 printf("\n\nRESULT :\nWavelenth for different spectral lines in Angstrom are following:\n\n");//RESULT OF THE EXPERIMENT
 printf("Violet  \t\t%f\n",lmd[0]);//violet
 printf("Blue    \t\t%f\n",lmd[1]);//blue
 printf("Green   \t\t%f\n",lmd[2]);//green
 printf("Yellow 1\t\t%f\n",lmd[3]);//yellow 1
 printf("Yellow 2\t\t%f\n",lmd[4]);//yellow 2
}
void numerical_aperture()//function body
{
    int i,l[5],d[5];//declaring necessary variables
    double NA[5],ANGLE[5],p,sum=0,t=0;//required variables
    printf("\n\nAIM : TO DETERMINE THE NUMERICAL APERTURE OF GIVEN STEP INDEX OPTICAL FIBRE\n\n");
    printf("APPARATUS  : Optical fiber kit, NA jig, mandrel, optical fibre\n\n");//printing apparatus required
    printf("FORMULA : NA = sin(a) =        D\n");//formula required
    printf("                        ---------------\n");
    printf("                        sqrt(4*L*L+D*D)\n\n");
    printf("               where , D = diameter of circle\n");
    printf("                       L = distance of screen\n");
    printf("               Acceptance Angle , a = asin(NA)\n");
    printf("\nEnter the Distance from screen in (mm)\n");//entering distance values
    for(i=0;i<5;i++)//loop for reading distance values
    {
        printf("For %d :",i+1);
        scanf("%d",&l[i]);
        printf("\n");
    }
    printf("Enter the Diameter of circle in (mm)\n");//entering diameter values
    for(i=0;i<5;i++)//loop for reading diameter values
    {
        printf("For %d :",i+1);
        scanf("%d",&d[i]);
        printf("\n");
    }
    printf("\nOBSERVATION TABLE : \n\n");//printing table
    printf("S.NO.\tDISTANCE OF SCREEN L(mm)\tDIAMETER OF CIRCLE D(mm)\tNA\t\tANGLE(DEGREE)\n");
    for(i=0;i<5;i++)//loop for calculating NA and acceptance angle
    {
        p=4*l[i]*l[i]+d[i]*d[i];
        NA[i]=d[i]/sqrt(p);
        ANGLE[i]=asin(NA[i]);//calculating numerical aperture
        ANGLE[i]=ANGLE[i]*180/3.14;//coverting from radian to degree
        printf("%d    \t\t  %d      \t\t\t  %d \t\t\t%f\t%f\n",i+1,l[i],d[i],NA[i],ANGLE[i]);//printing the values
        sum+=NA[i];
        t+=ANGLE[i];
    }
    printf("\nRESULT :\n\n");
    printf("NUMERICAL APERTURE OF OPTICAL FIBRE IS : %f\n\n",sum/5);
    printf("ACCEPTANCE ANGLE IS : %f degree\n",t/5);
}
void energy_gap()//function body
{
    int i,temp[10];//declaring necessary variables
    float tempk[10],tr[10],T[10],logr[10];//variable declaration
    double s,eg;//variable declaration
    printf("\n\n");
    printf("AIM : TO DETERMINE THE FORBIDDEN ENERGY GAP OF GIVEN THERMISTOR\n\n");
    printf("APPARATUS : Thermo resistor, Thermometer ,Heater ,Beaker and Multimeter .\n\n");//apparatus required for experiment
    printf("FORMULA : Eg = 2.303*2*k*slope\n");//formula
    printf("               ---------------\n");
    printf("                      e\n");
    printf("          where : k = boltzman constant\n");
    printf("                  e = charge of electron\n\n");
    printf("Enter the reading one by one\n");
    for(i=0;i<10;i++)//loop for enter values of temperature and resistance
    {
       printf("For %d reading : TEMPERATURE(C)\tTHERMISTOR RESISTANCE(in ohm)\n",i+1);
       scanf("%d%f",&temp[i],&tr[i]);//reading values
    }
    for(i=0;i<10;i++)//loop for (temperature conversion) and (temperature inverse) and (LOGR) values
    {
        tempk[i]=0;
        tempk[i]=temp[i]+273.15;//temperature conversion
        logr[i]=log10(tr[i]);//logr values
        T[i]=1/tempk[i];//temperature inverse
    }
    printf("\nOBSERVATION TABLE:\n\n");//table
    printf("S.No\t\tTEMPERATURE  \t\tTHERMISTOR RESISTANCE\tT=1/t\t\tLOG Rv \n");
    printf("    \t\t  (C)   (K)  \t\t        (ohm)        \t\n");
    printf("%d \t\t  %d    %f    \t\t%f       %f\t%f\n",1,temp[0],tempk[0],tr[0],T[0],logr[0]);
    for(i=1;i<10;i++)//loop for printing values
    { printf("%d \t\t  %d    %f    \t\t%f       %f\t        %f\n",i+1,temp[i],tempk[i],tr[i],T[i],logr[i]);//printing the respective values
    }
    s=((logr[5]-logr[4])/(T[5]-T[4]));//calculating slope
    printf("\nSLOPE OF THE PLOT IS :%f\n",s);//printing slope of the plot
    eg=2.303*2*s*0.8614*pow(10,-4);//calculating Eg
    printf("\n\nRESULT :\nTHE FORBIDDEN ENERGY GAP OF A THERMISISTOR IS : %f eV\n",eg);//printing energy gap
}

