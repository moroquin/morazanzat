#!/user/bin/env python
#Descargar e instalar Python3, pip3 y smbus
#importar libreria smbus
from smbus import SMBus

#addr es la direccion que se le coloco al esclavo
addr = 0x8
#La verdad no entendi esto pero es importante jajajaja
bus = SMBus(1)

#Procedimiento para enviar informacion al esclavo, cuando se agreguen mas
#esclavo se debera de agregar otro parametro que sea la direccion
def sendValue(value):
	bus.write_byte(addr, value)
	
#Posible funcion que recibe informacion del esclavo, al igual que con sendValue
#mas adelante se le debera agregar otro parametro para pedir la direccion del esclavo	
def readData():
	contador = bus.read_byte(addr)
	print("El contador es", contador)
	print("La cantidad de lluvia por xcm2 es: ", contador*5,"ml")
	
print("Selecciona:", " \n1 Solicitar Valor", "\n0 Enviar Valor")
while True:
	val = input("--->  ")
	if val == 1:
		readData()
	elif val == 0:
		sendValue(0)
	else:
		break

