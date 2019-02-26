
package koreatech.cse;

import java.util.HashMap;
import java.util.Map;
import com.fasterxml.jackson.annotation.JsonAnyGetter;
import com.fasterxml.jackson.annotation.JsonAnySetter;
import com.fasterxml.jackson.annotation.JsonIgnore;
import com.fasterxml.jackson.annotation.JsonInclude;
import com.fasterxml.jackson.annotation.JsonProperty;
import com.fasterxml.jackson.annotation.JsonPropertyOrder;

@JsonInclude(JsonInclude.Include.NON_NULL)
@JsonPropertyOrder({
    "attack",
    "defense",
    "magic",
    "difficulty"
})
public class Info {

    @JsonProperty("attack")
    private Long attack;
    @JsonProperty("defense")
    private Long defense;
    @JsonProperty("magic")
    private Long magic;
    @JsonProperty("difficulty")
    private Long difficulty;
    @JsonIgnore
    private Map<String, Object> additionalProperties = new HashMap<String, Object>();

    @JsonProperty("attack")
    public Long getAttack() {
        return attack;
    }

    @JsonProperty("attack")
    public void setAttack(Long attack) {
        this.attack = attack;
    }

    @JsonProperty("defense")
    public Long getDefense() {
        return defense;
    }

    @JsonProperty("defense")
    public void setDefense(Long defense) {
        this.defense = defense;
    }

    @JsonProperty("magic")
    public Long getMagic() {
        return magic;
    }

    @JsonProperty("magic")
    public void setMagic(Long magic) {
        this.magic = magic;
    }

    @JsonProperty("difficulty")
    public Long getDifficulty() {
        return difficulty;
    }

    @JsonProperty("difficulty")
    public void setDifficulty(Long difficulty) {
        this.difficulty = difficulty;
    }

    @JsonAnyGetter
    public Map<String, Object> getAdditionalProperties() {
        return this.additionalProperties;
    }

    @JsonAnySetter
    public void setAdditionalProperty(String name, Object value) {
        this.additionalProperties.put(name, value);
    }

}
