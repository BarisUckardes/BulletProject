#include "SphereGenerator.h"
#include <Graphics/Mesh/SphereQuad.h>
#include <Core/Symbols.h>
#include <glm/geometric.hpp>
#include <Graphics/Mesh/ExternalGenerator.h>
Array<SphereQuad> GenerateDefaultQuadSphere(float extent)
{
    Array<SphereQuad> quads;
    quads.Add(SphereQuad(glm::vec3(0,0,1)    ,glm::vec3(0, 1, 0)  , glm::vec3(1,0,0), extent));
    quads.Add(SphereQuad(glm::vec3(0, 0, -1), glm::vec3(0, 1, 0), glm::vec3(1, 0, 0), extent));
    quads.Add(SphereQuad(glm::vec3(1, 0, 0),  glm::vec3(0, 1, 0), glm::vec3(0, 0, 1), extent));
    quads.Add(SphereQuad(glm::vec3(-1, 0, 0), glm::vec3(0, 1, 0), glm::vec3(0, 0, 1), extent));
    quads.Add(SphereQuad(glm::vec3(0, 1, 0),  glm::vec3(0, 0, -1), glm::vec3(1, 0, 0), extent));
    quads.Add(SphereQuad(glm::vec3(0, -1, 0), glm::vec3(0, 0, 1), glm::vec3(1, 0, 0), extent));

    return quads;
}
Array<SphereQuad> GenerateRecursiveQuads(const Array<SphereQuad>& sourceQuads, unsigned int subdivisionLeft)
{
    Array<SphereQuad> quadsGenerated;

    /*
    * Iterete and subdivide
    */
    for (unsigned int i = 0; i < sourceQuads.GetCursor(); i++)
    {
        /*
        * Get quad
        */
        const SphereQuad quad = sourceQuads[i];

        /*
        * Generate sub quad centers
        */
        const float newExtent = quad.HalfExtent / 2.0f;

        SphereQuad quad0(quad.Center + (quad.RightVector * newExtent) + (-quad.UpVector*newExtent),quad.UpVector,quad.RightVector, newExtent);
        SphereQuad quad1(quad.Center + (quad.RightVector * newExtent) + (quad.UpVector * newExtent), quad.UpVector, quad.RightVector, newExtent);
        SphereQuad quad2(quad.Center + (-quad.RightVector * newExtent) + (-quad.UpVector * newExtent), quad.UpVector, quad.RightVector, newExtent);
        SphereQuad quad3(quad.Center + (-quad.RightVector * newExtent) + (quad.UpVector * newExtent), quad.UpVector, quad.RightVector, newExtent);

        quadsGenerated.Add(quad0);
        quadsGenerated.Add(quad1);
        quadsGenerated.Add(quad2);
        quadsGenerated.Add(quad3);
    }

    /*
    * Validate if no subdivisions left
    */
    if (subdivisionLeft == 1)
        return quadsGenerated;

    return GenerateRecursiveQuads(quadsGenerated, subdivisionLeft - 1);
}
void GenerateQuads(Array<SphereQuad>& quadsOut, unsigned int subdivisions)
{
    quadsOut = GenerateRecursiveQuads(quadsOut, subdivisions);
}

GeneratedSphereContent SphereGenerator::GenerateSphere(unsigned int subdivisionCount)
{
    /*
    * Generate shpere
    */
    Array<MeshVertex> vertexes;
    Array<int> indexes;
    NormalizedMesh normalizedMesh;
    NormalizedCube(5, normalizedMesh);

    /*
    * Create normals
    */
    for (int i = 0; i < normalizedMesh.vertices.GetCursor(); i++)
    {
        vertexes.Add(MeshVertex(normalizedMesh.vertices[i], normalizedMesh.vertices[i], glm::vec2(0)));
    }
    for (int i = 0; i < normalizedMesh.triangles.GetCursor(); i++)
    {
        int vector = normalizedMesh.triangles[i];
        indexes.Add(vector);
    }
    
    /*
    * Create content
    */
    GeneratedSphereContent content;
    content.Vertexes = vertexes;
    content.Indexes = indexes;
    return content;
}
