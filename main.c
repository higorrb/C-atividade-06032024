#include <stdio.h>

void Validarcpf(char cpf[12]){
    int soma1 = 0, soma2 = 0, digito1 = 0, digito2 = 0, iguais = 0, j, i;
    char inicial;

    inicial = cpf[0];
    for (i = 1; i < 11; i++)
    {
        if (cpf[i] != inicial)
        {
            iguais = 1;
            break;
        }
    }

    if (iguais == 0)
    {
        printf("Todos os numeros sao iguais, CPF Invalido...");
        return;
    }

    for (i = 10, j = 0; i>1 && j<10; i--, j++)
    {
        soma1 += (cpf[j] - '0') * i; 
    }
    
    digito1 = (soma1*10)%11;
    if (digito1 == 10)
    {
        digito1 = 0;
    }
    

    for (i = 11, j = 0; i>0 && j<10; i--, j++)
    {
        soma2 += (cpf[j] - '0') * i;
    }
    
    digito2 = (soma2*10)%11;
    if (digito2 == 10)
    {
        digito2 = 0;
    }
    

    if (digito1 != cpf[9] - '0' || digito2 != cpf[10] - '0')
    {
        printf("CPF invalido...\n");
    }
    else{
        printf("CPF valido!");
    }  
}



float ConvertHoraSeg(float horas){
    return horas * 3600;
}



void Adi(int a, int b)
{
    int soma = a + b;
    printf("%d + %d = %d\n", a, b, soma);
}

void Sub(int a, int b)
{
    int subtrai = a - b;
    printf("%d - %d = %d\n", a, b, subtrai);
}

void Mult(int a, int b)
{
    float multiplicar = a * b;
    printf("%d * %d = %.1f\n", a, b, multiplicar);
}
void Div(int a, int b){
    if ( b == 0)
    {
        printf("O segundo numero digitado foi ZERO, resultado invalido.");
    }
    else
    {
        float dividir = a / b;
        printf("%d / %d = %.1f", a, b, dividir);
    }
}



float CelFahren(float celsius){
    return (celsius*1.8)+32;
}
float FahrenCel(float fahrenheit){
    return (fahrenheit - 32) / 1.8;
}



void RealDolar(float real){
    float converte;
    converte = real * 0.2;
    printf("%.2f Real brasileiro igual a %.2f Dolar americano.", real, converte);
}
void DolarReal(float dolar){
    float converte;
    converte = dolar * 5;
    printf("%.2f Dolar americano igual a %.2f Real brasileiro.", dolar, converte);
}
void RealIene(float real){
    float converte;
    converte = real * 30;
    printf("%.2f Real brasileiro igual a %.2f Iene japones.", real, converte);
}
void IeneReal(float iene){
    float converte;
    converte = iene * 0.03;
    printf("%.2f Iene japones igual a %.2f Real brasileiro.", iene, converte);
}


int main(){
    int op, num1, num2, temperatura, moeda;
    char cpf[12];
    float horas, segundos, celsius, fahrenheit, valor;

    do
    {
        printf("\n\nMENU:\n[1]-Validar CPF\n[2]-Converter horas em segundos\n[3]-Calculadora\n[4]-Converter Temperaturas\n[5]-Converter Moedas\n[0]-Finalizar Programa\nOpcao:");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("Digite o seu CPF(apenas numeros): ");
            scanf("%s", cpf);
            Validarcpf(cpf);
            break;


        case 2:
            printf("Digite o horario:");
            scanf("%f", &horas);
            if (horas < 0)
            {
                printf("ERRO...Digite um numero maior que ZERO.");
                break;
            }
            segundos = ConvertHoraSeg(horas);
            printf("O horario digitado foi %.2f, que vale %.2f segundos", horas, segundos);
            break;


        case 3:
             printf("Digite o 1 numero:");
            scanf("%d", &num1);
            printf("Digite o 2 numero: ");
            scanf("%d", &num2);
            Adi(num1, num2);
            Sub(num1, num2);
            Mult(num1, num2);
            Div(num1, num2);
            break;


        case 4:
            printf("[1]-Celsius para Fahrenheit\n[2]-Fahrenheit para Celsius\n");
            printf("Escolha: ");
            scanf("%d", &temperatura);
            if (temperatura == 1)
            {
                printf("Digite a temperatura em Celsius:");
                scanf("%f", &celsius);
                fahrenheit = CelFahren(celsius);
                printf("A temperatura digitada vale %.1fF ", fahrenheit);
            }
            else if (temperatura == 2)
            {
                printf("Digite a temperatura em Fahrenheit:");
                scanf("%f", &fahrenheit);
                celsius = FahrenCel(fahrenheit);
                printf("A temperatura digitada vale %.1fC ", celsius);
            }
            break;
        

        case 5: 
            printf("[1]-Real para Dolar\n[2]-Dolar para Real\n[3]-Real para Iene\n[4]-Iene para Real\n");
            printf("Escolha: ");
            scanf("%d", &moeda);
            printf("Digite o valor que deseja converter: ");
            scanf("%f", &valor);
            switch (moeda)
            {
            case 1:
                RealDolar(valor);
                break;
            case 2:
                DolarReal(valor);
                break;
            case 3:
                RealIene(valor);
                break;
            case 4:
                IeneReal(valor);
                break;
            }
            break;
        }
    } while (op != 0);
    
    printf("Programa Finalizado!");


    return 0;
}