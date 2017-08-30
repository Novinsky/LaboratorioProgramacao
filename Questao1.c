//Questão 1 LAB.PROGRAM
#include<stdio.h>

float nota_valida(float nota1, float nota2, float nota3)
{
  int aux;
  float vetor[3], menor, nota_selecionada;
    vetor[0] = nota1;
    vetor[1] = nota2;
    vetor[2] = nota3;
    for(int i = 0; i < 2; i++){
      menor = vetor[i];
      aux = i;
      for(int j = i; j < 2; j++){
        if(menor > vetor[j+1]){
          menor = vetor[j+1];
          aux = j + 1;
        }
      }
      vetor[aux] = vetor[i];
      vetor[i] = menor;
    }
  nota_selecionada = vetor[1];
  return nota_selecionada;
}

void nota_final(float *originalidade,float *beleza){
  float final;
  final = (*originalidade * 0.6) + (*beleza * 0.4);
  printf("%.2f\n", final);
}

int main() {

  int i, id_inscricao, repete = 2;
  float notas[3], nota_teste, x, nota_originalidade, nota_beleza;
  float *originalidade, *beleza;

  while(repete > 0){
  if (repete == 2)
    printf("NOTAS DO CRITERIO ORIGINALIDADE!!!\n");
  if (repete == 1)
    printf("NOTAS DO CRITERIO BELEZA!!!\n");
  for(i = 0; i < 3; i++){
    do{
    printf("Digite a nota do jurado %d: ", i);
    scanf("%f", &nota_teste);
      if(nota_teste >= 0){
        notas[i] = nota_teste;
      }
      else
        printf("A nota digitada foi invalida, ela deve ser maior ou igual a 0!!!\n");
    }while(nota_teste < 0);
  }
    if(repete == 2){
      nota_originalidade = nota_valida(notas[0], notas[1], notas[2]);
    }
    if(repete == 1){
      nota_beleza = nota_valida(notas[0], notas[1], notas[2]);
    }
    repete--;
  }
  originalidade = &nota_originalidade;
  beleza = &nota_beleza;
  printf("A nota final do candidato foi: ");
  nota_final(originalidade, beleza);


  return 0;
}
