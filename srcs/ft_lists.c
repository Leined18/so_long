#include "so_long.h"

// Función para eliminar un nodo por su número de frame
void	deleteNode(t_img **head, int frameNumber)
{
	t_img	*temp;
	t_img	*prev;

	temp = *head;
	prev = NULL;
	if (temp != NULL && temp->frameNumber == frameNumber)
	{
		*head = temp->next;
		free(temp);
		return ;
	}
	while (temp != NULL && temp->frameNumber != frameNumber)
	{
		prev = temp;
		temp = temp->next;
	}
	if (temp == NULL)
	{
		ft_putstr_fd("No se encontró el frameNumber\n", 1);
		return ;
	}
	prev->next = temp->next;
	free(temp);
}

t_img	*createNode(int frameNumber)
{
	t_img	*newNode;

	newNode = (t_img *)malloc(sizeof(t_img));
	if (newNode == NULL)
	{
		printf("Error al asignar memoria.\n");
		exit(1);
	}
	newNode->frameNumber = frameNumber;
	newNode->next = NULL;
	return (newNode);
}

void	insertAtEnd(t_img **head, int frameNumber)
{
	t_img	*newNode;
	t_img	*temp;

	newNode = createNode(frameNumber);
	if (*head == NULL)
	{
		*head = newNode;
	}
	else
	{
		temp = *head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newNode;
	}
}

void	list(void)
{
	t_img data_img;
	t_img new;
	t_img *head;
	init_img(&data_img);
	init_img(&new);
	head = &data_img;
	data_img.next = &new;

	head->next = &new;
	while (head != NULL)
	{
		printf("head: %p\n", head);
		head = head->next;
	}
}