#AUTHOR: S.ABILASH

import numpy as np


#Encode

msg = input("Enter your message: ")
print("MSG: "+msg)
key = [ [1,2,1],[2,3,2],[2,2,1] ]
alpha = []
for i in range(ord('A'),ord('Z')+1):
    alpha.append(chr(i))

msg_ascii =[]
for i in msg:
    msg_ascii.append(alpha.index(i))

result_ascii=[]

for i in range(len(key)):
    k=0
    value = 0
    for j in range(len(key[i])):
        value += key[i][j] * msg_ascii[k]
        k+=1
    result_ascii.append(value)
encode=""
for i in range(len(result_ascii)):
    encode+=alpha[result_ascii[i]%26]
print("ENC: "+encode)

#Decode

key_inverse= np.array(key)
key_inverse = np.linalg.inv(key_inverse)
key_inverse = key_inverse.tolist()
enc_ascii =[]
for i in encode:
    enc_ascii.append(alpha.index(i))
enc_result_ascii=[]
for i in range(len(key_inverse)):
    k=0
    value =0
    for j in range(len(key_inverse[i])):
        value+= key_inverse[i][j] * enc_ascii[k]
        k+=1
    enc_result_ascii.append(value)
decode =""
for i in range(len(enc_result_ascii)):
    decode+= alpha[int(enc_result_ascii[i]%26)]
print("DEC: "+decode)

