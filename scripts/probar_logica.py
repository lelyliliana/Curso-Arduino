
"""Verifica las funciones usadas por los sketches con compilador C++ nativo."""
from pathlib import Path
import argparse,shutil,subprocess,tempfile,sys
p=argparse.ArgumentParser();p.add_argument('--cxx');a=p.parse_args()
cxx=a.cxx or shutil.which('g++') or shutil.which('clang++')
if not cxx:raise SystemExit('Se requiere g++ o clang++ de escritorio; la compilacion AVR se realiza por separado con compilar.py.')
r=Path(__file__).resolve().parents[1]
with tempfile.TemporaryDirectory(prefix='arduino-logica-') as temp:
 out=Path(temp)/('logica.exe' if sys.platform=='win32' else 'logica')
 subprocess.run([cxx,'-std=c++11','-Wall','-Wextra','-Werror','-pedantic',str(r/'tests/logica.cpp'),'-o',str(out)],check=True)
 subprocess.run([str(out)],check=True)
