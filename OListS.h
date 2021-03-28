#pragma once

template<typename Type>
struct OList {
	Type info;
	OList* next;
};

template<typename Type>
OList<Type>* OListS_Make() {
	OList<Type>* list = new(OList<Type>);
	list->info = 0;
	list->next = NULL;
	return list;
}

template<typename Type>
void OListS_Add(OList<Type>* list, Type value) {
	OList<Type>* created = new(OList<Type>);
	created->info = value;
	OList<Type>* obj = list;
	while (obj->next != NULL) obj = obj->next;
	obj->next = created;
	created->next = NULL;
}

template<typename Type>
void OListS_Add(OList<Type>* list, Type value, int number) {
	if (number > OListS_Size(list)) OListS_Add(list, value);
	else if (number > 0) {
		OList<Type>* created = new(OList<Type>);
		created->info = value;
		OList<Type>* obj = list;
		int i = 0;
		while (i+1 != number) {
			obj = obj->next;
			i++;
		}
		created->next = obj->next;
		obj->next = created;
	}
}

template<typename Type>
int OListS_Size(OList<Type>* list) {
	OList<Type>* obj = list;
	int i = 0;
	while (obj != NULL) {
		obj = obj->next;
		i++;
	}
	return i;
}

template<typename Type>
Type OListS_Get(OList<Type>* list, int number) {
	if (number > 0) {
		OList<Type>* obj = list;
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
void OListS_Swap(OList<Type>* list, int first, int second) {
	if (first > 0 && first <= OListS_Size(list) && second > 0 && second <= OListS_Size(list) && first != second) {
		OList<Type>* obj = list;
		OList<Type>* tf = NULL, * ts = NULL;
		int i = 0;
		while (obj != NULL && (tf == NULL || ts == NULL)) {
			if (i+1 == first) tf = obj;
			else if (i+1 == second) ts = obj;
			i++;
			obj = obj->next;
		}

		OList<Type>* f, *s, *ff, *fs;
		f = tf->next;
		s = ts->next;
		ff = f->next;
		fs = s->next;

		tf->next = s;
		s->next = ff;

		ts->next = f;
		f->next = ff;
	}
}

template<typename Type>
void OListS_Remove(OList<Type>* list) {
	if (OListS_Size(list) > 0) {
		OList<Type>* obj = list, *deleted;
		while (obj->next->next!= NULL) {
			obj = obj->next;
		}
		deleted = obj->next;
		obj->next = NULL;
		delete deleted;
	}
}

template<typename Type>
void OListS_Remove(OList<Type>* list, int number) {
	if (OListS_Size(list) > 0) {
		if (number >= OListS_Size(list)) OListS_Remove(list);
		else if (number > 0) {
			OList<Type>* obj = list, deleted;
			int i = 0;
			while (i+1 != number) {
				obj = obj->next;
				i++;
			}
			deleted = obj->next;
			obj->next = obj->next->next;
			delete deleted;
		}
	}
}

template<typename Type>
int OListS_Find(OList<Type>* list, Type element) {
	int i;
	OList<Type>* obj = list->next;
	for (i = 1; i <= OListS_Size(list); i++)
	{
		if (element == obj->info) return i;
		obj = obj->next;
	}
	return -1;
}

template<typename Type>
int OListS_Rfind(OList<Type>* list, Type element) {
	int i;
	for (i = OListS_Size(list); i > 0; i--)
	{
		if (element == OLitsS_Get(list, i)) return i;
	}
	return -1;
}

template<typename Type>
bool OListS_Is_exists(OList<Type>* list, Type element) {
	if (OListS_Find(list, element) == -1) return false;
	else return true;
}
