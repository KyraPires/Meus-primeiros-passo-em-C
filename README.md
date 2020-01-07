<h3>Este é o trabalho final da disciplina Linguagem de Programação</h3>

O trabalho consistiu em criar um programa que lesse um arquivo texto com as informações da fatura.

O enunciado do trabalho:

<p>>1. Crie um programa que leia um arquivo texto contendo informações de faturas. O programa deverá validar o arquivo, segundo critérios pré-determinados, gerar uma listagem dos erros e mostrar em tela as faturas que estão com os dados corretos. Ao final, o programa deverá exibir a soma de faturas por fornecedor.</p>
<p>a) Criar uma função para leitura e validação: ler o arquivo fatura.txt (de acordo com o layout acima). Os registros corretos serão inseridos numa matriz de struct. Os registros inválidos serão armazenados no arquivo texto “ErroFatura.txt.</p>
<p>➔ Considera-se registro inválido aquele cuja quantidade ou valor unitário seja igual a zero. Se num mesmo registro, o valor e o quantidade forem iguais a zero, gerar duas linhas no arquivo de erro, uma para cada erro. No arquivo de erro deve ser copiada a linha inteira (no mesmo formato que foi lido) e ao final acrescenta-se o texto “QUANTIDADE DEVE SER MAIOR QUE ZERO” ou “VALOR DEVE SER INFORMADO”-> A cada execução do programa, o arquivo de erro deverá ser reinicializado.</p>
<p>b) Criar uma função que exiba em tela as faturas corretas através da matriz de struct, em ordem de número de fatura.</p>
<p>c)Criar uma função que exiba o fornecedor e a soma do total de seus respectivos produtos nas faturas.</p>
<p>➔ Deverá ser utilizada a função SUBSTRING criada anteriormente em aula para “quebrar” a linha lida do arquivo e separá-la de acordo com o layout do arquivo.</p>
