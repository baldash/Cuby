package com.keimyung.baldash.cuby.Handlers;

import com.keimyung.baldash.cuby.GameObjects.GameObject;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class EntitiesHandler {

    private static final EntitiesHandler instance = new EntitiesHandler();

    private Map<String, GameObject> entities;

    private EntitiesHandler()
    {
        entities = new HashMap<>();
    }

    public static EntitiesHandler getInstance()
    {
        return instance;
    }

    public Map<String, GameObject> getEntities()
    {
        return entities;
    }

    public GameObject getEntity(String name)
    {
        return entities.get(name);
    }

    public void addEntity(String name, GameObject entity)
    {
        entities.put(name, entity);
    }

    public List<GameObject> getAllEntitiesOfName(String name)
    {
        List<GameObject> foundEntities = new ArrayList<>();

        for(String key: entities.keySet()) {
            if (key.contains(name))
                foundEntities.add(entities.get(key));
        }
        
        return foundEntities;
    }

    public boolean contains(String name)
    {
        return entities.containsKey(name);
    }

    public boolean contains(GameObject value)
    {
        return entities.containsValue(value);
    }

    public void remove(String name)
    {
        entities.remove(name);
    }

}
