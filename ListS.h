#pragma once

template<typename Type>
struct List {
	Type info;
	List* next;
	List* previous;
};

template<typename Type>
List<Type>* ListS_Make() {
	List<Type>* list = new(List<Type>);
	list->info = 0;
	list->next = NULL;
	list->previous = NULL;
	return list;
}

template<typename Type>
void ListS_Add(List<Type>* list, Type value) {
	List<Type>* created = new(List<Type>);
	created->info = value;
	List<Type>* obj = list;
	while (obj->next != NULL) obj = obj->next;
	obj->next = created;
	created->previous = obj;
	created->next = NULL;
}

template<typename Type>
void ListS_Add(List<Type>* list, Type value, int number) {
	if (number > ListS_Size(list)) ListS_Add(list, value);
	else if (number > 0){
		List<Type>* created = new(List<Type>);
		created->info = value;
		List<Type>* obj = list;
		int i = 0;
		while (i != number) {
			obj = obj->next;
			i++;
		}
		created->previous = obj->previous;
		created->next = obj;
		obj->previous->next = created;
		obj->previous = created;
	}
}

template<typename Type>
int ListS_Size(List<Type>* list) {
	List<Type>* obj = list;
	int i = 0;
	while (obj != NULL) {
		obj = obj->next;
		i++;
	}
	return i;
}

template<typename Type>
Type ListS_Get(List<Type>* list, int number) {
	if (number > 0) {
		List<Type>* obj = list;
		int i = 0;
		while (obj != NULL) {
			if (i == number) return obj->info;
			else {
				i++;
				obj = obj->next;
			}
		}
	}
	return -1;
}

template<typename Type>
void ListS_Swap(List<Type>* list, int first, int second) {
	if (first > 0 && first <= ListS_Size(list) && second > 0 && second <= ListS_Size(list) && first != second) {
		List<Type>* obj = list;
		List<Type>* f = NULL, * s = NULL;
		int i = 0;
		while (obj != NULL && (f == NULL || s == NULL)) {
			if (i == first) f = obj;
			else if (i == second) s = obj;
			i++;
			obj = obj->next;
		}

		List<Type>* tp, * tn;
		tp = f->previous;
		tn = f->next;

		if (f->previous != NULL) f->previous->next = s;
		if (f->next != NULL) f->next->previous = s;

		if (s->previous != NULL) s->previous->next = f;
		if (s->next != NULL) s->next->previous = f;

		f->previous = s->previous;
		f->next = s->next;

		s->previous = tp;
		s->next = tn;
	}
}

template<typename Type>
void ListS_Remove(List<Type>* list) {
	if (ListS_Size(list) > 0) {
		List<Type>* obj = list;
		while (obj->next != NULL) {
			obj = obj->next;
		}
		obj->previous->next = NULL;
		delete obj;
	}
}

template<typename Type>
void ListS_Remove(List<Type>* list, int number) {
	if (ListS_Size(list) > 0) {
		if (number >= ListS_Size(list)) ListS_Remove(list);
		else if (number > 0) {
			List<Type>* obj = list;
			int i = 0;
			while (i != number) {
				obj = obj->next;
				i++;
			}
			obj->previous->next = obj->next;
			if(obj->next != NULL) obj->next->previous = obj->previous;
			delete obj;
		}
	}
}

template<typename Type>
int ListS_Find(List<Type>* list, Type element) {
	int i;
	List<Type>* obj = list->next;
	for (i = 1; i <= ListS_Size(list); i++)
	{
		if (element == obj->info) return i;
		obj = obj->next;
	}
	return -1;
}

template<typename Type>
int ListS_Rfind(List<Type>* list, Type element) {
	int i;
	List<Type>* obj = ListS_Get(list, ListS_Size(list));
	for (i = ListS_Size(list); i > 0; i--)
	{
		if (element == obj->info) return i;
		obj = obj->previous;
	}
	return -1;
}

template<typename Type>
bool ListS_Is_exists(List<Type>* list, Type element) {
	if (ListS_Find(list, element) == -1) return false;
	else return true;
}
