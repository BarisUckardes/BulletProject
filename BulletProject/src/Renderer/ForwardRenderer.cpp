#include "ForwardRenderer.h"
#include <GL/glew.h>
#include <World/Components/Spatial.h>

void ForwardRenderer::Render(const Array<RenderableComponent*>& renderables, const Array<ObserverComponent*>& observerComponents)
{
	/*
	* Get window properties
	*/
	const Window* window = GetWindow();
	const unsigned int width = window->GetWidth();
	const unsigned int height = window->GetHeight();

	/*
	* Iterate observers
	*/
	for (unsigned int observerIndex = 0; observerIndex < observerComponents.GetCursor(); observerIndex++)
	{
		/*
		* Get observer
		*/
		const ObserverComponent* observer = observerComponents[observerIndex];

		/*
		* Get observer properties
		*/
		const glm::vec4 clearColor = observer->GetClearColor();
		const glm::mat4x4 projectionMatrix = observer->GetProjectionMatrix();
		const glm::mat4x4 viewMatrix = observer->GetViewMatrix();

		/*
		* Bind framebuffer
		*/
		glBindFramebuffer(GL_FRAMEBUFFER, 0);

		/*
		* Clear framebuffer
		*/
		glClearColor(clearColor.x,clearColor.y,clearColor.z,1.0f);
		glClearDepth(1.0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		/*
		* Set viewport
		*/
		glViewport(0, 0, width, height);

		/*
		* Iterate renderables
		*/
		for (unsigned int renderableIndex = 0; renderableIndex < renderables.GetCursor(); renderableIndex++)
		{
			/*
			* Get renderable
			*/
			const RenderableComponent* renderable = renderables[renderableIndex];

			/*
			* Get renderable properties
			*/
			const Mesh* mesh = renderable->GetMesh();
			const ShaderProgram* program = renderable->GetProgram();
			const glm::mat4x4 modelMatrix = renderable->GetSpatial()->GetModelMatrix();
			const glm::mat4x4 mvpMatrix = projectionMatrix * viewMatrix * modelMatrix;
			const glm::mat4x4 mv = viewMatrix * modelMatrix;
			const glm::mat4x4 pv = projectionMatrix * viewMatrix;
			const glm::vec4 customColor = renderable->GetColor();
			//const glm::mat4x4 mvpMatrix = projectionMatrix * viewMatrix;
			//const glm::mat4x4 mvpMatrix = projectionMatrix * viewMatrix * modelMatrix;
			//const glm::mat4x4 mvpMatrix = projectionMatrix;
			//const glm::mat4x4 mvpMatrix = viewMatrix;
			const unsigned int vertexArrayIndex = mesh->GetVertexArrayIndex();
			const unsigned int vertexBufferIndex = mesh->GetVertexBufferIndex();
			const unsigned int indexBufferIndex = mesh->GetIndexBufferIndex();
			const unsigned int indexCount = mesh->GetIndexCount();
			const unsigned int programIndex = program->GetProgramIndex();

			/*
			* Bind mesh
			*/
			glBindVertexArray(vertexArrayIndex);
			glBindBuffer(GL_ARRAY_BUFFER, vertexBufferIndex);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferIndex);

			/*
			* Use program
			*/
			glUseProgram(programIndex);

			/*
			* Set shader uniforms(if any)
			*/
			glUniformMatrix4fv(
				glGetUniformLocation(programIndex, "v_Mvp"),
				1,
				GL_FALSE,
				&mvpMatrix[0][0]);
			glUniformMatrix4fv(
				glGetUniformLocation(programIndex, "v_Model"),
				1,
				GL_FALSE,
				&pv[0][0]);
			glUniform4fv(glGetUniformLocation(programIndex, "f_Color"), 1, &customColor.x);

			/*
			* Issue draw call
			*/
			glDrawElements(GL_TRIANGLES, indexCount, GL_UNSIGNED_INT, nullptr);
		}
	}
}
