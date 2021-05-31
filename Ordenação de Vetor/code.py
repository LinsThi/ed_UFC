import matplotlib.pyplot as plt
#Definindo uma janela para a plotagem dos graficos
plt.figure(num=None, figsize=(12, 6), dpi=500, facecolor='w', edgecolor='k')
#Leia o arquivo com as colunas 'pemutation' e 'time'
archive = open("file.md")
# Red = r, Blue = b, Black = k, White = w
cor_plot = 'b' 
#Procure cores Hexadecimais
cor_label = '#FFFFFF' 
x, y = [], []    
for line in archive:
    colls = line.split()		#Dividindo a linha em colunas separadas por espaço
    x.append(int(colls[0]))		#Levando a Lista x os dados do eixo X
    y.append(float(colls[1]))	#Levando a Lista y os dados do eixo Y
plt.plot(x, y, cor_plot+"p-", label = 'Tempo x Permutação') #Plotando os eixos no grafico
#Definindo caracteristicas da Legenda
plt.legend(loc='upper left', shadow=True, fontsize='x-large').get_frame().set_facecolor(cor_label)
plt.ylabel("Tempo: 300 * clock()")	    #Legenda eixo Y
plt.xlabel("Permutações: 10 em 10")		            	    #Legenda eixo X
plt.title("Grafico QuickSort")		    #Titulo do grafico
plt.grid()			                    #Coloca grade no grafico (opcional)
plt.savefig("img.png") 		            #Diretorio para salvar o arquivo
#plt.show()			                    #Mostra o grafico apos executar o script(opcional)
#plt.clf()			                    #Limpa a figura do grafico (caso queira executar o script inumeras vezes)


'''
Fiquem avontade para modificar o script conforme o gosto e a necessidade
dos senhores, para mais informacoes leiam a documentação da bibilioteca 
matplotlib do python.
'''
