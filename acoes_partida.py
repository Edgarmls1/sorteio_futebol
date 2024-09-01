import os.path
import numpy as np
import random
import pandas as pd
from datetime import datetime

historico = []

def menu():
    print('#MENU#')
    print('1 - Simular Partida')
    print('2 - Historico de Partidas')
    print('3 - Salvar')
    print('4 - Partidas Anteriores')
    print('5 - Sair')

def partida():
    gc = 0 
    gv = 0 
    tempo = 0
    tmpgc = [] 
    tmpgv = []

    time_casa = input('Time da Casa: ')
    time_vizitante = input('Time Vizitante: ')

    while tempo < 18:
        tempo+=1

        area = random.randint(0,21)

        if area <=1 :
            tmpgc.append(random.randint(0,91))
            gc += 1
        elif area >= 19 :
            tmpgv.append(random.randint(0,91))
            gv += 1

    jogo = f'{time_casa} {gc} X {gv} {time_vizitante}'

    historico.append(jogo)

    print(jogo)
    print(f'{np.sort(tmpgc)}   {np.sort(tmpgv)}')

def mostrar_historico():
    print('partidas da sessao')
    print(historico)

def partidas_anteriores():
    df = pd.read_csv('historico.csv')
    print(df)

def salvar():
    df_hist = pd.DataFrame(historico, columns=['jogos'])
    df_hist['dia'] = datetime.now().strftime('%d/%m/%Y')
    print('salvando historico de partidas da sessão...')

    if os.path.isfile('historico.csv'):
        df = pd.read_csv('historico.csv')
        df = pd.concat([df, df_hist], ignore_index=True)
        df.to_csv('historico.csv', index = False)
    else:
        df_hist.to_csv('historico.csv', index = False)

    print('historico salvo em csv')