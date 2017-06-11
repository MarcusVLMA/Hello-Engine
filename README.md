# Hello-Engine
Mudanças 06/06/17

-> Camera.h:

	- cameraName passou a ser String ao invés de ponteiro char.
  

-> SaltyEngine.cpp:

	- StandarVectorOfVertex foi apenas para o .cpp (Construtor) e inicializado com tamanho 4 (.resize).

	- Uso do assert para encerrar o programa caso não exista um principalCharacter.

	- funções renderFrame e moveFromKeyboard foram declaradas no .h antes.

	- Checagem: antes de usar activeCamera, verificar se ela existe.

	- No método createSprite(), o valor padrão do parâmetro opcional ownVectorOfVertex ficou apenas no .h.

	- No método createCamera(), o valor padrão do parâmetro opcional *sprite ficou apenas no .h.
  

-> SaltyEngine.h:

	- Parâmetro *name do método createCamera() deixou de ser char para ser const char.

	- O método principalCharacter() foi renomeado para setMainCharacter().
  

-> SaltyEngineIncludes.h:

	- Adição do (#pragma once) para que o código não fique fazendo um "looping de includes".

	- #include das classes declarado depois do #include das bibliotecas de containers, pois as classes usam as bibliotecas.

	- Cada classe foi declarada antes.
		//?  
