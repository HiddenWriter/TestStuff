#ifndef PCH_H
#define PCH_H

enum class PHASE
{
	MAIN, BACKSPACE, STORAGE, CONTAINER, UNKNOWN
};

#include <memory>
#include <string>
#include <iostream>
#include <ostream>
#include <exception>

#include "BaseHeap.h"
#include "HeapMax.h"
#include "HeapMin.h"
#include "BinaryTree.h"
#include "DoublyLinkedList.h"
#include "SortedList.h"

#include "BaseItem.h"
#include "ItemType.h"
#include "ContainerType.h"
#include "StorageType.h"

#include "BasePhase.h"
#include "PhaseMain.h"
#include "PhaseStorage.h"
#include "PhaseContainer.h"

#include "DataBox.h"
#include "Application.h"

#endif // !PCH_H
