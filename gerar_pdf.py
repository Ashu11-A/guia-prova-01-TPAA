import os
from pylatex import Document, Section, Subsection, Command
from pylatex.utils import NoEscape, escape_latex

def configurar_preambulo_e_estilo(doc):
    """Configura o preâmbulo do LaTeX com pacotes essenciais e o estilo do código."""
    # Suporte a UTF-8 para todo o documento
    doc.packages.append(Command('usepackage', 'inputenc', 'utf8'))
    doc.packages.append(Command('usepackage', 'fontenc', 'T1'))
    
    # Pacotes para o estilo do código
    doc.packages.append(Command('usepackage', 'listings'))
    doc.packages.append(Command('usepackage', 'xcolor'))

    # Definindo cores personalizadas
    doc.preamble.append(NoEscape(r'\definecolor{codegreen}{rgb}{0,0.6,0}'))
    doc.preamble.append(NoEscape(r'\definecolor{codegray}{rgb}{0.5,0.5,0.5}'))
    doc.preamble.append(NoEscape(r'\definecolor{codepurple}{rgb}{0.58,0,0.82}'))
    doc.preamble.append(NoEscape(r'\definecolor{backcolour}{rgb}{0.98,0.98,0.98}'))

    # Configurando o estilo do 'listings' para ser mais compacto
    doc.preamble.append(NoEscape(r'\lstdefinestyle{mystyle}{'
                                r'    backgroundcolor=\color{backcolour},'
                                r'    commentstyle=\color{codegreen},'
                                r'    keywordstyle=\color{magenta},'
                                r'    numberstyle=\tiny\color{codegray},'
                                r'    stringstyle=\color{codepurple},'
                                r'    basicstyle=\scriptsize\ttfamily,' 
                                r'    breakatwhitespace=false,'
                                r'    breaklines=true,'
                                r'    captionpos=b,'
                                r'    keepspaces=true,'
                                r'    numbers=left,'
                                r'    numbersep=5pt,'
                                r'    showspaces=false,'
                                r'    showstringspaces=false,'
                                r'    showtabs=false,'
                                r'    tabsize=2'
                                r'}'))
    doc.preamble.append(NoEscape(r'\lstset{style=mystyle}'))

    # Garante que caracteres acentuados funcionem DENTRO do código
    doc.preamble.append(NoEscape(r'\lstset{literate='
        r'{á}{{\'a}}1 {é}{{\'e}}1 {í}{{\'i}}1 {ó}{{\'o}}1 {ú}{{\'u}}1 '
        r'{Á}{{\'A}}1 {É}{{\'E}}1 {Í}{{\'I}}1 {Ó}{{\'O}}1 {Ú}{{\'U}}1 '
        r'{à}{{\`a}}1 {è}{{\`e}}1 {ì}{{\`i}}1 {ò}{{\`o}}1 {ù}{{\`u}}1 '
        r'{À}{{\`A}}1 {È}{{\'E}}1 {Ì}{{\`I}}1 {Ò}{{\`O}}1 {Ù}{{\`U}}1 '
        r'{ä}{{\"a}}1 {ë}{{\"e}}1 {ï}{{\"i}}1 {ö}{{\"o}}1 {ü}{{\"u}}1 '
        r'{Ä}{{\"A}}1 {Ë}{{\"E}}1 {Ï}{{\"I}}1 {Ö}{{\"O}}1 {Ü}{{\"U}}1 '
        r'{â}{{\^a}}1 {ê}{{\^e}}1 {î}{{\^i}}1 {ô}{{\^o}}1 {û}{{\^u}}1 '
        r'{Â}{{\^A}}1 {Ê}{{\^E}}1 {Î}{{\^I}}1 {Ô}{{\^O}}1 {Û}{{\^U}}1 '
        r'{ã}{{\~a}}1 {õ}{{\~o}}1 {Ã}{{\~A}}1 {Õ}{{\~O}}1 '
        r'{ç}{{\c c}}1 {Ç}{{\c C}}1 '
        r'}'))


def gerar_pdf_de_codigos(diretorio_raiz, nome_arquivo_saida):
    """
    Gera um PDF a partir dos arquivos de código em um diretório, com ordenação correta.
    """
    # Configurações do documento
    geometria = {"tmargin": "0.8in", "lmargin": "0.8in", "rmargin": "0.8in", "bmargin": "0.8in"}
    doc = Document(geometry_options=geometria, document_options=['twocolumn'])
    
    # Configura todo o preâmbulo e estilos
    configurar_preambulo_e_estilo(doc)

    # Adiciona o título do documento
    doc.preamble.append(Command('title', 'Documentação de Códigos'))
    doc.preamble.append(Command('author', 'Gerado Automaticamente'))
    doc.preamble.append(Command('date', NoEscape(r'\today')))
    doc.append(NoEscape(r'\maketitle'))
    
    # Percorre o diretório de códigos
    for root, dirs, files in os.walk(diretorio_raiz, topdown=True):
        # --- MUDANÇA PRINCIPAL: Ordena as listas de diretórios e arquivos ---
        dirs.sort()
        files.sort()
        
        # Ignora o diretório raiz para não criar uma seção "codes"
        if root == diretorio_raiz:
            continue
            
        nome_da_pasta = os.path.basename(root)
        
        if files:
            with doc.create(Section(escape_latex(nome_da_pasta.replace('-', ' ').replace('_', ' ')), numbering=False)):
                for file_name in files:
                    if file_name.endswith('.cpp'):
                        caminho_completo = os.path.join(root, file_name)
                        
                        with doc.create(Subsection(escape_latex(file_name.replace('_', ' ')), numbering=False)):
                            try:
                                with open(caminho_completo, 'r', encoding='utf-8') as f:
                                    codigo = f.read()
                                    
                                    # Insere o bloco de código de forma segura
                                    bloco_de_codigo = (
                                        r'\begin{lstlisting}[language=C++]' + '\n'
                                        + codigo
                                        + '\n' + r'\end{lstlisting}'
                                    )
                                    doc.append(NoEscape(bloco_de_codigo))

                            except Exception as e:
                                print(f"Erro ao ler o arquivo {caminho_completo}: {e}")

    # Gera o PDF
    try:
        doc.generate_pdf(nome_arquivo_saida, clean_tex=True, compiler='pdflatex')
        print(f"PDF '{nome_arquivo_saida}.pdf' gerado com sucesso!")
    except Exception as e:
        print(f"Erro ao gerar o PDF. Verifique se sua distribuição LaTeX está instalada e funcionando.")
        print(f"Erro: {e}")

if __name__ == '__main__':
    diretorio_dos_codigos = 'codes'
    nome_do_pdf = 'documento_final_ordenado'
    gerar_pdf_de_codigos(diretorio_dos_codigos, nome_do_pdf)