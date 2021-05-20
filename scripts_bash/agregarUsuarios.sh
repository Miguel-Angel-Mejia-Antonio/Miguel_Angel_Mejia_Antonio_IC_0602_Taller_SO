#!/bin/bash
ROOT_UID=0
SUCCESS=0

#Ingresar como root
if [ "$UID" -ne "$ROOT_UID" ]
then
  echo "Se debe estar como root para ejecutar este script"
  exit $E_NOTROOT
fi  

#Verificacion de la existencia del archivo de los usuarios a ingresar
file=$1

if [ "${file}X" = "X" ];
then
   echo "Debe indicar el archivo con el listado de usuarios a agregar..."
   exit 1
fi
# Del archivo con el listado de usuarios a agregar:
# Este es el formato:
# ejemplo:pass1234:6000:54335:infromacionmiguel:/home/miguel:/bin/bash:
#    |   
#    f1  
#$f1 = username
agregarUsuario(){
	#echo "----> Agregar Usuario <----" Variables que usaremos para asignar los diferentes valores de un usuario
	eval user="$1"
	eval password="$2"
	eval userid="$3"
	eval grupoid="$4"
	eval useridinfo="$5"
	eval directorio="$6"
	eval shell="$7"
    
    #Ejemplo a Implementar
    #ejemplo:pass1234:6000:54335:infromacionmiguel:/home/miguel:/bin/bash:
    if grep -q ${grupoid} /etc/group #Buscamos si el grupo existe para agregar el usuario.
    then
    echo "Grupo encontrado"
    if grep -q "${user}" /etc/passwd #Buscamos el usuario, si existe mandar un mensaje de que existe, si no existe crear el usuario
    then #
    echo "El ususario [${user}] No se pudo agregar por que ya EXISTE..."
    else
    #Ejecutamos el comando para agregar nuestro usuario con sus diferentes configuraciones
    useradd -c "${userid} ${useridinfo}"  -p "${password}" -d "${directorio}" -s "${shell}" "${user}" -u  "${grupoid}"
    echo "El usuario [${user}] fue agregado correctamente..."
    fi
    else
    echo "El grupo: ${grupoid} NO EXISTE para agregar al usuario: [${user}]" #Si el grupo no existe no agregamos al usuario
    fi
}

while IFS=: read -r f1 f2 f3 f4 f5 f6 f7
do
    agregarUsuario "\${f1}" "\${f2}" "\${f3}" "\${f4}" "\${f5}" "\${f6}" "\${f7}"
done < ${file}
exit 0
