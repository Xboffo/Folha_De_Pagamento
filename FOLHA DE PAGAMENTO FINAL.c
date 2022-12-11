
/* Alunos:
    Kauet Boffo De lima - 05222-069
    Vincius de Freitas Yashuda - 0522-072
*/


#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

 double CalculateFGTS(double baseSalary) {
    return baseSalary * 0.08;
}

double CalculateIRRF(double baseSalary)
        {
            double discountPercentage = 0, tax = 0;

            	if(baseSalary >= 1903.99 && baseSalary <= 2826.65)
            {
                discountPercentage = 0.075;
                tax = 142.80;
            }
            	if(baseSalary >= 2826.66 && baseSalary <= 3751.05)
            {
                discountPercentage = 0.15;
                tax = 354.80;
            }
            	if (baseSalary >= 3751.06 && baseSalary <= 4664.68)
            {
                discountPercentage = 0.225;
                tax = 636.13;
            }
            	if (baseSalary >= 4664.69)
            {
                discountPercentage = 0.275;
                tax = 869.36;
            }

            	return (baseSalary * discountPercentage) - tax;
        }
        
double CalculateDiscountValue1stSalaryRange( double maximumValue, double discountPercentage)
		{
				return   maximumValue * discountPercentage;
		}

double CalculateDiscountValue2ndSalaryRange(  double maximumValue,double minimumValue,  double discountPercentage)
		{	
				return (maximumValue - minimumValue) * discountPercentage;
		}
    
double CalculateDiscountValue3rdSalaryRange(double maximumValue, double minimumValue,double discountPercentage)
   		{
   				return (maximumValue - minimumValue) * discountPercentage;
	  	}   
          

double CalculateDiscountValueCurrentSalaryRange(  double baseSalary,double minimumRangeValue,double rangeDiscountPercentage)
		{
				return (baseSalary - minimumRangeValue) * rangeDiscountPercentage;
		}
        
       		

double CalculateINSS(double baseSalary)
        {
            double discountValue1stRange = CalculateDiscountValue1stSalaryRange(1212.0, 0.075);
            double discountValue2ndRange = CalculateDiscountValue2ndSalaryRange(2427.35, 1212.01, 0.09);
            double discountValue3rdRange = CalculateDiscountValue3rdSalaryRange(3641.03, 2427.36, 0.12);
            double totalDiscountValue = discountValue1stRange;

            if (baseSalary > 1212.0 && baseSalary < 2427.36)
                totalDiscountValue = discountValue1stRange + CalculateDiscountValueCurrentSalaryRange(baseSalary, 1212.01, 0.09);

            if (baseSalary > 2427.35 && baseSalary < 3641.04)
                totalDiscountValue = discountValue1stRange + discountValue2ndRange + CalculateDiscountValueCurrentSalaryRange(baseSalary, 2427.36, 0.12);

            if (baseSalary > 3641.03 && baseSalary < 7087.23)
                totalDiscountValue = discountValue1stRange + discountValue2ndRange + discountValue3rdRange + CalculateDiscountValueCurrentSalaryRange(baseSalary, 3641.04, 0.14);

            return totalDiscountValue;
        }

double CalculateVacation (double baseSalary)
	{
			return(baseSalary/3)+baseSalary;
	}

       

int main(void) 
	
        {
        	setlocale(LC_ALL, "Portuguese");
        	
        	double baseSalary,paymentVacation,valueFoodVouncher=0,valueTransportationVouncher=0,netSalary;
        	char name [100], employment[100], responsibility[100], place[100];
        	int overtime,foodVoucher,transportationVoucher;
        	
    printf ("Por favor, digie o Nome : ");
		fgets (name, 100 ,stdin); 
		
	printf ("Por favor, digite o emprego atual : ");
		fgets (employment, 100 ,stdin); 
		
	printf ("Por favor, digite o cargo atual : ");
		fgets (responsibility, 100 ,stdin); 
		
	printf ("Por favor, digite o Local onde trabalha : ");
		fgets (place, 100 ,stdin); 
		
	printf ("Por favor, digite o valor salario bruto: ");
		scanf ("%lf", &baseSalary);
	
	system("cls");	
	printf ("Por favor, Digite se Recebe Vale Transporte : ");
	printf ("\n\t\t1 - Sim / 2 - Não  ");
		scanf ("%d",&transportationVoucher);
		
		if(transportationVoucher==1)
	{
	printf ("Por favor, digite a porcentagem de desconto do Vale Transporte  : ");
		scanf ("%lf",&valueTransportationVouncher);
	}	
	system("cls");
	printf ("Por favor, Digite se Recebe Vale Alimentação : ");
	printf ("\n\t\t1 - Sim / 2 - Não  ");
		scanf ("%d",&foodVoucher);

		if(foodVoucher==1)
	{
	printf ("Por favor, digite a porcentagem de desconto do Vale Alimentação  : ");
		scanf ("%lf",&valueFoodVouncher);
	}
	system("cls");
	printf ("Por favor, Digite se Funcionario tirou Férias nesse mes: : ");
	printf ("\n\t\t1 - Sim / 2 - Não  ");
	scanf ("%d",&overtime); 
	

		valueFoodVouncher= baseSalary * (valueFoodVouncher/100);
		valueTransportationVouncher= baseSalary * (valueTransportationVouncher/100);			
		netSalary= baseSalary - (CalculateINSS(baseSalary) + CalculateIRRF(baseSalary) + CalculateFGTS(baseSalary) + valueTransportationVouncher + valueFoodVouncher );
		system("cls");
		
		printf ("\nNome : %s", name);
		printf ("\nEmprego : %s", employment);
		printf ("\nCargo : %s", responsibility);
		printf ("\nSalário Bruto : %.2lf", baseSalary);
		
		if (overtime== 1)
		printf ("\nPagamento das férias : %.2lf", CalculateVacation(baseSalary) );
		else 
		printf ("\nFuncionario não recebeu férias esse mês.");
		
	if(valueFoodVouncher > 0 )
		printf ("\nValor Vale Alimentação :%.2lf", valueFoodVouncher);
	else
				printf ("\nNão recebe Vale Alimentação.");
	
	if(valueTransportationVouncher > 0 )
		printf ("\nValor Vale Transporte :%.2lf", valueTransportationVouncher);
	else
				printf ("\nNão recebe Vale Transporte.");	
		printf ("\nDesconto INSS : %.2lf", CalculateINSS(baseSalary) );
		printf ("\nDesconto IRRF : %.2lf", CalculateIRRF(baseSalary) );
		printf ("\nValor FGTS : %.2lf", CalculateFGTS(baseSalary) );
		printf ("\nSalario Liquido: %.2lf", netSalary);
		
return 0;
}

