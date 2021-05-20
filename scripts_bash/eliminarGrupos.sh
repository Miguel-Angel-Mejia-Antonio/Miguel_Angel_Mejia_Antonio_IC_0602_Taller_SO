#!/bin/bash
ROOT_UID=0
SUCCESS=0

#VAlidacion de la ejecucion en modo root
if [ "$UID" -ne "$ROOT_UID" ]
then
  echo "Se debe estar como root para ejecutar este script"
  exit $E_NOTROOT
fi  

#Se comprueba que el archivo con el listado de grupos a eliminar exista
file=$1

if [ "${file}X" = "X" ];
then
   echo "Debe indicar el archivo del listado con Nombres de grupo a eliminar..."
   exit 1
fi

# Del archivo con el listado de grupos a eliminar:
# Este es el formato:
# ejemplo
#    |   
#    f1  
#$f1 = nombreGrupo

eliminarGrupo(){
	#echo "----> Crear Grupo <----"
	eval nombreGrupo="$1"
	#echo "nombreGrupo 		  = ${nombreGrupo}"
	#echo "-------------------------"
	
	#-p, --password PASSWORD
    #Note: This option is not recommended because the password (or encrypted password) will be visible by users listing the processes.
    #You should make sure the password respects the system's password policy.
	groupdel "${nombreGrupo}" #escribimos el nombre del grupo a eliminar
	if [ $? -eq $SUCCESS ];
	then
		echo "Grupo [${nombreGrupo}] eliminado correctamente..."
	else
		echo "Grupo [${nombreGrupo}] No se pudo eliminar por que no existe..."
	fi
}

while IFS=: read -r f1
do
	eliminarGrupo "\${f1}"	
done < ${file}

exit 0