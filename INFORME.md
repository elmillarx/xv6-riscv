# Tarea0: Instalacion y ejecucion de xv6

## Pasos seguidos
1. Clonar el repositorio en pc 
- Se clona https://github.com/mit-pdos/xv6-riscv.git
- 'cd xv6-riscv'

2. Crear una rama llamada 'grupoc_t0'
- 'git checkout -b grupoc_t0'

3. Instalar Dependencias
- Al intentar hacer el make entrega un error, se instala riscv-tools
- 'brew tap riscv/riscv'
- 'brew install riscv-tools'
- Y se instala tambien QEMU

4. Compilar xv6 con 'make'

5. Ejecutar xv6 con 'make qemu'

6. Verificar
- xv6 se ejecuto correctamente y los comandos funcionan:
- ls
- echo "Hola xv6"
- cat README
- Para salir Ctrl+A y luego X

7. INFORME.md
8. captura.png

9. Commit y Push
- Al hacer el commit sale error ya que se intenta hacer push al repositorio original
- En la pagina de GitHub se crea el Fork
- Se cambia al el Fork con 'git remote set-url origin https://github.com/elmillarx/xv6-riscv.git'
- Se verifica con 'git remote -v'
- Se hace push con: 
- 'git add .'
- 'git commit -m "Tarea0: Instalacion y Ejecucion xv6"'
- 'git push origin grupoc_t0'