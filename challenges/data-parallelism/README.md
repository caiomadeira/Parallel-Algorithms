# Structured Parallel Programming

Nesse treinamento o aluno irá obter conhecimentos básicos sobre programação paralela estruturada em arquiteturas de memória compartilhada.

Esse diretório possui a seguinte organização:

- Uma pasta chamada `src` que possui as aplicações sequenciais.
- Uma pasta chamada `benchmark` que possui binários paralelos.

O desempenho das versões paralelas precisa ficar melhor ou próximo do resultado obtido pelos binários da pasta `benchmark`

# Entregáveis

Cada atividade é formada pela paralelização de uma aplicação. Ao final, espera-se que o aluno entregue:
- Um breve relatório descrevendo a paralelização da aplicação. (10 linhas no máximo)
- Um gráfico comparando as diferentes paralelizações. O eixo X contém o número de threads e o eixo Y o tempo de execução. Os testes devem ter sido executados pelo menos 3 vezes e o desvio padrão deve aparecer no gráfico.
- Uma breve discussão dos resultados justificando o desempenho. (20 linhas no máximo)

# APIs para Programação Paralela estruturada
- OpenMP
- FastFlow
- OneTBB

# Primeira parte

Na primeira parte, será focado em paralelismo de dados. Para isso, espera-se que o aluno utilize os padrões Map e MapReduce para paralelizar as aplicações na ordem detalhada abaixo. O aluno deve pesquisar como implementar os padrões paralelos Map e MapReduce em cada uma das APIs. 

1. Paralelizar a aplicação de números primos.
2. Paralelizar a aplicação mandelbrot
3. Paralelizar a aplicação kmeans
4. Paralelizar a aplicação EP do NPB.
5. Paralelizar a aplicação FT do NPB.
6. Paralelizar a aplicação CG do NPB.
7. Paralelizar a aplicação MG do NPB.


# Segunda parte

Na segunda parte, será focado em paralelismo de stream.
